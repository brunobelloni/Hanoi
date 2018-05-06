import os, csv, cv2
import Utils as ut

imagem = cv2.imread("imagens/4.jpg")
contours = ut.getContours(imagem)
x2, y2, r2 = ut.getCordenadas(imagem)
arquivo_t1, arquivo_t2, arquivo_t3  = open("tipo 1.csv", "w"), open("tipo 2.csv", "w"), open("tipo 3.csv", "w")

for contour in contours:
    area = cv2.contourArea(contour)
    if 80 < area < 3500:
        (x, y), r = cv2.minEnclosingCircle(contour)
        dist = ut.getDistAb(x2, x, y2, y) 

        if  dist < r2 - 300:
            per = cv2.arcLength(contour, True)
            hu = cv2.HuMoments(cv2.moments(contour))
            cv2.drawContours(imagem, contour, -1, (0, 255, 255), 1)
            cv2.destroyAllWindows()
            ut.showImage(x, y, r, imagem)
            key = cv2.waitKey(0)

            os.system("cls")
            if key == 49: arquivo_t1.write(ut.getCsv(hu)), print("Classificado no tipo 1")
            elif key == 50: arquivo_t2.write(ut.getCsv(hu)), print("Classificado no tipo 2")
            elif key == 51: arquivo_t3.write(ut.getCsv(hu)), print("Classificado no tipo 3")
            else: print("Não foi classificado")

arquivo_t1.close(), arquivo_t2.close(), arquivo_t3.close()

print("Classificacao concluida!")
