import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import interp1d

# 定义数据
current = np.array([0.0, 0.0, 0.0, 0.01, 0.23, 1.73, 4.0, 5.72, 10.44, 13.47, 19.42, 31.92])
voltage = np.array([0.015, 0.1451, 0.2308, 0.3104, 0.4653, 0.544, 0.5851, 0.6046, 0.6399, 0.6552, 0.6775, 0.7056])

# 设置图片清晰度
plt.rcParams['figure.dpi'] = 300

# 设置 matplotlib 支持中文，字体改为 SimHei
plt.rcParams['font.sans-serif'] = ['SimHei']
# 解决负号显示问题
plt.rcParams['axes.unicode_minus'] = False

# 适当扩展电压范围，这里在最小值和最大值基础上分别扩展 10%
min_voltage_extended = min(voltage) * 0.9
max_voltage_extended = max(voltage) * 1.05

# 创建更密集的电压值用于插值，使用扩展后的范围
voltage_new = np.linspace(min_voltage_extended, max_voltage_extended, 500)

# 使用 interp1d 进行插值，kind='cubic' 表示使用三次样条插值
# 设置 fill_value='extrapolate' 来允许外推
f = interp1d(voltage, current, kind='cubic', fill_value='extrapolate')
current_smooth = f(voltage_new)

# 创建图形，适当增大图形尺寸
plt.figure(figsize=(8, 6))
plt.xlim(0, 1.0)
plt.ylim(0, 35)
plt.yticks(np.arange(0, 41, 5))

# 绘制原始数据点
plt.scatter(voltage, current, s=20, color='black', label='原始数据点')

# 绘制光滑曲线
plt.plot(voltage_new, current_smooth, label='光滑曲线', color='blue')

# 找到 2 mA 和 8 mA 对应的索引（使用线性插值）
idx_2mA = np.searchsorted(current_smooth, 2)
idx_8mA = np.searchsorted(current_smooth, 8)

# 进行线性插值获取对应的电压值
if idx_2mA < len(current_smooth):
    v_2mA = np.interp(2, [current_smooth[idx_2mA - 1], current_smooth[idx_2mA]],
                      [voltage_new[idx_2mA - 1], voltage_new[idx_2mA]])
    plt.scatter(v_2mA, 2, color='red', label='2 mA 点')
    plt.annotate(f'({v_2mA:.4f}, 2)', (v_2mA, 2), textcoords='offset points', xytext=(0, 5), ha='center')

if idx_8mA < len(current_smooth):
    v_8mA = np.interp(8, [current_smooth[idx_8mA - 1], current_smooth[idx_8mA]],
                      [voltage_new[idx_8mA - 1], voltage_new[idx_8mA]])
    plt.scatter(v_8mA, 8, color='green', label='8 mA 点')
    plt.annotate(f'({v_8mA:.4f}, 8)', (v_8mA, 8), textcoords='offset points', xytext=(0, 5), ha='center')

# 添加标题和标签
plt.title('二极管伏安特性曲线')
plt.xlabel('电压 (V)', labelpad=5)
plt.ylabel('电流 (mA)')

# 添加网格线
plt.grid(True)

# 添加图例
plt.legend()

# 调整子图布局，通过 subplots_adjust 函数手动设置边距
plt.subplots_adjust(bottom=0.15, left=0.15)

# 保存图片
plt.savefig('二极管.png', bbox_inches='tight')

# 显示图形
plt.show()