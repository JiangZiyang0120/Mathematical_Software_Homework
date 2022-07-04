import matplotlib.pyplot as plt

a = open("data.txt","r")
b = list()

for lines in a:
    b.append(lines.split())

dic = b[0]
newton = b[1]

for i in range(len(dic)):
    dic[i] = eval(dic[i])

for i in range(len(newton)):
    newton[i] = eval(newton[i])

plt.title('The number of iterations')  # 折线图标题
plt.xlabel('x')  # x轴标题
plt.ylabel('iter times')  # y轴标题
plt.plot(dic)
plt.plot(newton)
plt.legend(['Dichotomy','Newton Method'])
plt.savefig('item.png')
plt.show()

print("生成图片成功")