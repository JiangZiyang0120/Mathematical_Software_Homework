import numpy as np
import matplotlib.pyplot as plt
from MandelbrotComp import getEscapeTime

# 最大迭代次数
MAX_ITER_NUMBER = 200
# 逃逸区间
ESCAPE_RANGE = 20

# 图片保存路径
IMAGE_PATH = 'mandelbrotNext.png'

# xCenter, yCenter描述曼德博集图像的显示中心
# width 为图像的宽度。也因此最终图像为一个正方形
# N 为图像单边将要分为的离散点的个数。
# 图像的总点数为 N*N
def Manderbrot(xCenter, yCenter, width, N):
    pixelWidth = width / N
    xLeftLine = xCenter - width / 2
    yDownLine = yCenter - width / 2
    Colors = np.zeros([N, N], dtype=int)
    color = 0
    InterWidth = MAX_ITER_NUMBER / 5
    for x in range(N):
        for y in range(N):
            times = getEscapeTime(complex(xLeftLine + x * pixelWidth,
                                          yDownLine + y * pixelWidth))
            Colors[y][x] = (MAX_ITER_NUMBER - times) * 0x00FFFF
    plt.matshow(Colors)
    plt.savefig(IMAGE_PATH)
    plt.show()


Manderbrot(-0.7214576, 0.2421354, 0.02, 3000)
