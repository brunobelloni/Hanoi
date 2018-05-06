def getContours(imagem):
    from cv2 import cvtColor, threshold, morphologyEx, findContours, COLOR_BGR2GRAY, THRESH_BINARY, MORPH_OPEN, MORPH_CLOSE, RETR_TREE, CHAIN_APPROX_NONE
    from numpy import ones, uint8
    cinza = cvtColor(imagem, COLOR_BGR2GRAY)
    ret, thresh = threshold(cinza, 110, 255, THRESH_BINARY)
    opening = morphologyEx(thresh, MORPH_OPEN, ones((2, 4), uint8))
    closing = morphologyEx(opening, MORPH_CLOSE, ones((2, 4), uint8))
    thresh, contours, hierarchy = findContours(closing, RETR_TREE, CHAIN_APPROX_NONE)
    return contours

def getCordenadas(imagem):
    from cv2 import cvtColor, threshold, HoughCircles, COLOR_BGR2GRAY, THRESH_BINARY_INV, HOUGH_GRADIENT
    from numpy import uint16, around
    cinza = cvtColor(imagem, COLOR_BGR2GRAY)
    ret, thresh = threshold(cinza, 130, 255, THRESH_BINARY_INV)
    circles = HoughCircles(thresh, HOUGH_GRADIENT, 22, 1000000)

    if circles is not None:
        circles = uint16(around(circles))
        x, y, r = 0, 0, 0
        for i in circles[0,:]:
            if r < i[2]:
                x, y, r = i[0], i[1], i[2]
        # cv2.circle(imagem, (x, y), r, (0, 0, 255), 2)
        # a, b, _ = imagem.shape
        # imagem = cv2.resize(imagem, (int(a * 0.2), int(b * 0.2)))
        # cv2.imshow(" ", imagem)
        # cv2.waitKey(0)
        return x, y, r
    else:
        return print("Ocorreu um erro!")

def getColor():
    from random import randint
    sort = randint(1, 3)
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
    return var[0] + "," + var[1] + "," + var[2] + "," + var[3] + "," + var[4] + "," + var[5] + "," + var[6] + "\n"

def showImage(xA, yA, rA, imagem):
    from cv2 import imshow
    margin = 25
    y, y1 = int(yA) - int(rA + margin), int(yA) + int(rA + margin)
    x, x1 = int(xA) - int(rA + margin), int(xA) + int(rA + margin)
    imshow("Classificacao", imagem[y:y1, x:x1])
