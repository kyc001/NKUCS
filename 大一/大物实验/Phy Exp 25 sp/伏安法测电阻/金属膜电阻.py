import numpy as np
import matplotlib.pyplot as plt

# 定义数据
current = np.array([3.540,7.200,10.56,14.16,23.6,29.9,35.8,41.8])
voltage = np.array([0.50,1.04,1.51,2.01,2.54,3.01,3.50])

# 进行线性拟合
fit = np.polyfit(voltage, current, 1)
fit_fn = np.poly1d(fit)

# 设置图片清晰度
plt.rcParams['figure.dpi'] = 300

# 设置 matplotlib 支持中文
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 创建图形，适当增大尺寸
plt.figure(figsize=(10, 8))

# 绘制测量点
plt.scatter(voltage, current, label='测量点', color='red')


# 绘制拟合曲线
plt.plot(voltage, fit_fn(voltage), label='拟合曲线', color='blue')

# 添加标题和标签
plt.title('S-E关系图')
plt.xlabel('E', labelpad=5)
plt.ylabel('S')

# 添加网格线
plt.grid(True)

# 添加图例
plt.legend()

# 调整子图布局，通过 subplots_adjust 函数手动设置边距
plt.subplots_adjust(bottom=0.15, left=0.15)

# 保存图片
plt.savefig('金属膜电阻.png', bbox_inches='tight')

# 显示图形
plt.show()