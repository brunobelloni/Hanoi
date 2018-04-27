import cv2
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

from math import sqrt
from Methods import cor
from Methods import cordenadas

imagem = cv2.imread('imagens/4.jpg')
copy = imagem.copy()
cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(cinza, 110, 255, cv2.THRESH_BINARY)
kernel = np.ones((3, 3), np.uint8)
opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, 2)
closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)
thresh, contours, hierCirclerchy = cv2.findContours(closing, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
xCircle, yCircle, rCircle = cordenadas(cinza)

vetor = []

contador = 0
for contour in contours:
    area = cv2.contourArea(contour)

    if 120 < area < 3500:
        (xA, yA), rA = cv2.minEnclosingCircle(contour)
        distAB = sqrt(((xCircle - xA) ** 2) + ((yCircle - yA) ** 2))

        if distAB < rCircle - 300:
            per = cv2.arcLength(contour, True)
            contador = contador + 1
            # balance = (area * 0.7) + (per * 0.3)
            vetor.append(area)
            margin = 25
            y, y1 = int(yA) - int(rA + margin), int(yA) + int(rA + margin)
            x, x1 = int(xA) - int(rA + margin), int(xA) + int(rA + margin)

            tipo = ""
            cor = (0, 0, 0)
            if(120 < area < 1125.5):
                tipo, cor = "1", (255, 0, 0)
            elif(1125.5 <= area < 2130.5):
                tipo, cor = "2", (0, 255, 0)
            elif(area >= 2130.5):
                tipo, cor = "3", (0, 0, 255)

            cv2.imwrite("Classificacao\\Tipo " + tipo + "\\" + str(contador) + ".jpg", copy[y:y1, x:x1])
            cv2.drawContours(imagem, contour, -1, cor, 2)
            # cv2.putText(imagem, "A: " + str(area), (int(xA), int(yA)), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)
            # cv2.putText(imagem, "P: " + str(per), (int(xA), int(yA) + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)

cv2.imwrite("Final " + str(contador) + ".jpg", imagem)
print("Identificações: " + str(contador))

'''
sns.set()
plt.hist(vetor, bins = 3)
plt.xlabel('Balance')
plt.ylabel('Quantidade')
plt.title("Histograma")
plt.show()
'''
