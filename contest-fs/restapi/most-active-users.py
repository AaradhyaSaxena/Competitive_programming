# Most Active Authors

# Rest API contains information about a collection of users and articles they have written. 
# Given a threshold value the goal is to get a list of most active authors, with submission count greater than threshold.
# API URL: https://jsonmock.hackerrank.com/api/article_users?page=<pageNumber>

# The function should return an array of strings that represent the usernames of users whose submission count is greater
# than the given threshold. The usernames in the array must be ordered in the order they appear in the API response

import requests
import json

def getUsernames(threshold):
    # set variables
    usernames = []
    page = 1
    totalPages = 1

    while page <= totalPages:
        # make request for each page
        apiRequest = requests.get('https://jsonmock.hackerrank.com/api/article_users?page=' + str(page))
        articles = apiRequest.json()['data']

        # set totalPages value
        if page == 1:
            totalPages = apiRequest.json()['total_pages']

        # get data for each user
        for value in articles:
            submissionCount = value['submission_count']

            # check if submissionCount is greater than threshold
            if submissionCount > threshold:
                usernames.append(value['username'])

        # go to next page
        page += 1

    usernamesInNewLine = '\n'.join(map(str, usernames))
    return usernamesInNewLine


names = getUsernames(10)
print(names)