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

# arrayA = []
# arrayP = []

vetor = []

contador = 0
for contour in contours:
    area = round(cv2.contourArea(contour), 1)

    if 120 < area < 3500:
        (xA, yA), rA = cv2.minEnclosingCircle(contour)
        distAB = sqrt(((xCircle - xA) ** 2) + ((yCircle - yA) ** 2))

        if distAB < rCircle - 300:
            per = round(cv2.arcLength(contour, True), 1)
            contador = contador + 1
            # arrayA.append(area)
            # arrayP.append(per)

            balance = (area * 0.7) + (per * 0.3)
            vetor.append(balance)

            margin = 40
            y, y1 = int(yA) - int(rA + margin), int(yA) + int(rA + margin)
            x, x1 = int(xA) - int(rA + margin), int(xA) + int(rA + margin)

            if(98 < balance < 832):
                tipo, cor = "1", (255, 0, 0)
            elif(832 <= balance < 1566):
                tipo, cor = "2", (0, 255, 0)
            elif(area >= 1566):
                tipo, cor = "3", (0, 0, 255)

            cv2.imwrite("Classificacao\\Tipo " + tipo + "\\" + str(contador) + ".jpg", copy[y:y1, x:x1])
            cv2.drawContours(imagem, contour, -1, cor, 2)
            # cv2.putText(imagem, "A: " + str(area), (int(xA), int(yA)), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)
            # cv2.putText(imagem, "P: " + str(per), (int(xA), int(yA) + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2, cv2.LINE_AA)

cv2.imwrite("Final " + str(contador) + ".jpg", imagem)
print("Final " + str(contador))


sns.set()
plt.hist(vetor, bins = 300)
plt.xlabel('Area/Perimetro')
plt.ylabel('Quantidade')
plt.title("HistogrCirclema Area/Perimetro")
plt.show()
