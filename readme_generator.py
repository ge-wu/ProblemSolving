#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import requests
import json


def get_problems():
    api_url = "https://leetcode.com/api/problems/algorithms/"
    resp = requests.get(api_url)
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
    return data


def main():
    repo_url = "https://github.com/ge-wu/LeetCode/blob/main/"
    data = get_problems()

    readme_header = "# LeetCode\n " \
                    "All solutions are written by me in C++. " \
                    "The main purpose is daily entertainment. " \
                    "So not meant for tutorial, thus, no explanation are included. \n"
    diff = {3: ":red_circle:", 2: ":yellow_circle:", 1: ":green_circle:"}

    f = open("README.md", 'w')
    f.write(readme_header)

    for root, _, files in os.walk("./"):
        if "git" in root or root == "./":
            continue
        f.write("#### " + root[2:] + '\n')
        for filename in sorted(files):
            if ".cpp" not in filename:
                continue
            problem_id = int(filename.split('.')[0])
            file_url = repo_url + root[2:] + '/' + filename
            try:
                difficulty = diff[data[problem_id]["difficulty"]]
                display_title = f'{problem_id}. {data[problem_id]["title"]}'
                full_title = f'{difficulty} [{display_title}]({file_url})  '
                f.write(full_title + '\n')
            except KeyError:
                continue
    f.close()


if __name__ == "__main__":
    main()
