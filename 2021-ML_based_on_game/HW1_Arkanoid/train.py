from sklearn import datasets
import os
import pickle
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import StratifiedShuffleSplit

# load in pickles
for i in range(45, 125):
    file_path = f'../training_data/random ({i}).pickle'
    file = open(file_path, "rb")
    data = pickle.load(file)
    if i == 45:
        game_info = data['ml']['scene_info']
        game_command = data['ml']['command']
    else:
        game_info += data['ml']['scene_info']
        game_command += data['ml']['command']
    file.close()

# get features from all data
for i in range(1, len(game_info) - 1): # start from second element(first is for default)
    g = game_info[i]

    ball_speed_x = g['ball'][0] - game_info[i - 1]['ball'][0]
    ball_speed_y = g['ball'][1] - game_info[i - 1]['ball'][1]

    if ball_speed_x > 0:
        if ball_speed_y > 0:
            Direction = 0
        else:
            Direction = 1
    else:
        if ball_speed_y > 0:
            Direction = 2
        else:
            Direction = 3

    if i == 1:
        feature = [g['ball'][0], g['ball'][1], g['platform'][0], ball_speed_x, ball_speed_y, Direction]
    else:
        feature = np.vstack((feature, [g['ball'][0], g['ball'][1], g['platform'][0], ball_speed_x, ball_speed_y, Direction])) # stack the data (combine array)

    if game_command[i] == "MOVE_LEFT":
        game_command[i] = -1
    elif game_command[i] == "MOVE_RIGHT":
        game_command[i] = 1
    else:
        game_command[i] = 0

answer = np.array(game_command[1:-1])

# train model with data
x_train, x_test, y_train, y_test = train_test_split(feature, answer, test_size=0.3, random_state=9)
clf = KNeighborsClassifier(n_neighbors=3)
clf.fit(x_train, y_train)

# save the result
file = open('model.pickle', 'wb')
pickle.dump(clf, file)
file.close()