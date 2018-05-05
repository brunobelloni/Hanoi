import os
import csv
import cv2
import Methods as ut

imagem = cv2.imread("imagens/4.jpg")

contours = ut.getContours(imagem)
xC, yC, rC = ut.getCordenadas(imagem)

arquivo_t1, arquivo_t2, arquivo_t3  = open("tipo 1.csv", "w"), open("tipo 2.csv", "w"), open("tipo 3.csv", "w")

for contour in contours:
    area = cv2.contourArea(contour)

    if 80 < area < 3500:
        (x, y), r = cv2.minEnclosingCircle(contour)

        if ut.getDistAb(xC, x, yC, y) < rC - 300:
            hu = cv2.HuMoments(cv2.moments(contour))
            per = cv2.arcLength(contour, True)

            cv2.drawContours(imagem, contour, -1, (0, 255, 255), 1)

            ut.showImage(x, y, r, imagem)

            key = cv2.waitKey(0)

            if key == 49:
                arquivo_t1.write(ut.getCsv(hu))
                print("Classificado no tipo 1")
            elif key == 50:
                arquivo_t2.write(ut.getCsv(hu))
                print("Classificado no tipo 2")
            elif key == 51:
                arquivo_t3.write(ut.getCsv(hu))
                print("Classificado no tipo 3")
            else:
                print("Não foi classificado")
            os.system("cls")

arquivo_t1.close()
arquivo_t2.close()
arquivo_t3.close()

print("Classificacao concluida!")
