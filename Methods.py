import cv2
import random
import numpy as np


def cordenadas(imagem):
    ret, thresh = cv2.threshold(imagem, 130, 255, cv2.THRESH_BINARY_INV)
    circles = cv2.HoughCircles(thresh, cv2.HOUGH_GRADIENT, 22, 1000000)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        x, y, r = 0, 0, 0
        for i in circles[0,:]:
            if r < i[2]:
                x, y, r = i[0], i[1], i[2]
        # cv2.circle(imagem, (x, y), r, (0, 0, 255), 2)
        return x, y, r
    else:
        return 0


def cor():
    sort = random.randint(1, 3)
    if sort == 1:
        return 255, 0, 0
    elif sort == 2:
        return 0, 255, 0
    elif sort == 3:
        return 0, 0, 255
