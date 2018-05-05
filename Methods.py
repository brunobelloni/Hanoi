def getContours(imagem):
    import cv2
    import numpy as np
    cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(cinza, 110, 255, cv2.THRESH_BINARY)
    opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, np.ones((2, 4), np.uint8))
    closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, np.ones((2, 4), np.uint8))
    thresh, contours, hierarchy = cv2.findContours(closing, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
    return contours

def getCordenadas(imagem):
    import cv2
    import numpy as np
    cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(cinza, 130, 255, cv2.THRESH_BINARY_INV)
    circles = cv2.HoughCircles(thresh, cv2.HOUGH_GRADIENT, 22, 1000000)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        x, y, r = 0, 0, 0
        for i in circles[0,:]:
            if r < i[2]:
                x, y, r = i[0], i[1], i[2]
        return x, y, r
    else:
        return 0

def getColor():
    import random
    sort = random.randint(1, 3)
    if sort == 1:
        return 255, 0, 0
    elif sort == 2:
        return 0, 255, 0
    elif sort == 3:
        return 0, 0, 255

def getDistAb(xC, xA, yC, yA):
    from math import sqrt
    return sqrt(((xC - xA) ** 2) + ((yC - yA) ** 2))

def getCsv(hu):
    var = []
    for i in range(0, 7):
            var.append(format(str(float(hu[i]))[:10]))
    string = var[0] + "," + var[1] + "," + var[2] + "," + var[3] + "," + var[4] + "," + var[5] + "," + var[6] + "\n"
    return string

def showImage(xA, yA, rA, imagem):
    import cv2
    y, y1 = int(yA) - int(rA + 25), int(yA) + int(rA + 25)
    x, x1 = int(xA) - int(rA + 25), int(xA) + int(rA + 25)
    cv2.imshow("Classificacao", imagem[y:y1, x:x1])
