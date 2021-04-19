#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import requests
import json


def get_problems():
    api_url = "https://leetcode.com/api/problems/algorithms/"
    session = requests.Session()
    resp = session.get(api_url)
    question_json = json.loads(resp.content.decode("utf-8"))

    data = {}

    questions = question_json["stat_status_pairs"]
    for question in questions:
        stat = question["stat"]
        
        frontend_id = stat["frontend_question_id"]
        difficulty = question["difficulty"]["level"]
        question_title = stat["question__title"]
        question_title_slug = question_title.replace(' ', '_')

        data[int(frontend_id)] = {
            "title": question_title,
            "title_slug": question_title_slug,
            "difficulty": int(difficulty)
        }
    print(data)
    return data

def main():
    repo_url = "https://github.com/ge-wu/LeetCode/blob/main/"
    data = get_problems()

    readme_header = "# LeetCode\n Only medium and above problems are included. All "\
        "solutions are written by me in C++. The main purpose is daily entertainment\n"

    f = open("README.md", 'w')
    f.write(readme_header)
    
    for root, _, files in os.walk("./"):
        if "git" in root or root == "./":
            continue
        f.write("#### " + root[2:] + '\n')
        for filename in sorted(files):
            problem_id = int(filename.split('.')[0])
            file_url = repo_url + root[2:] + '/' + filename
            difficulty = ":red_circle:" if data[problem_id]["difficulty"] == 3 else ":full_moon:"
            display_title = f'{problem_id}. {data[problem_id]["title"]}'
            full_title = f'{difficulty} [{display_title}]({file_url})  '
            f.write(full_title + '\n')

    f.close()


if __name__ == "__main__":
    main()
