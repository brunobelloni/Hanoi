import cv2
import numpy as np
from math import sqrt
from Methods import Cordenadas
from Methods import CorRandomica

imagem = cv2.imread('imagens/4.jpg')
cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(cinza, 100, 255, cv2.THRESH_BINARY_INV)

'''
# Threshold
# Morfologia, Erosão, Dilatação...

kernel = np.ones((2, 2), np.uint8)
opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations = 2)
'''

thresh, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
Xa, Ya, Ra = Cordenadas(cinza)

contador = 0
for contour in contours:
    area = round(cv2.contourArea(contour), 1)

    if area > 100 and area < 2500:
        (Xb, Yb), Rb = cv2.minEnclosingCircle(contour) # x, y e raio #
        distAB = sqrt(((Xa - Xb) ** 2) + ((Ya - Yb) ** 2))

        if(distAB < Ra - 500):
            per = round(cv2.arcLength(contour, True) , 1) # Perimetro #
            contador = contador + 1

            cv2.drawContours(imagem, contour, -1, CorRandomica(), 2)
            cv2.putText(imagem, "A: " + str(area), (int(Xa), int(Ya)), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)
            cv2.putText(imagem, "P: " + str(per), (int(Xa), int(Ya) + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)

cv2.imwrite("Final " + str(contador) + ".jpg", imagem)
print("Ok")
