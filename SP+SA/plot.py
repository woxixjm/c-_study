import matplotlib.pyplot as plt
import matplotlib.patches as patches

fig = plt.figure(figsize = (10,10) )

ax = fig.add_subplot(111)

rec_a = plt.Rectangle((0,0),8,4,linewidth=2, edgecolor='black', facecolor='green')
rec_b = plt.Rectangle((5,9),3,8,linewidth=2, edgecolor='black', facecolor='blue')
rec_c = plt.Rectangle((0,4),5,6,linewidth=2, edgecolor='black', facecolor='red')
rec_d = plt.Rectangle((5,4),3,5,linewidth=2, edgecolor='black', facecolor='orange')
rec_e = plt.Rectangle((0,10),5,6,linewidth=2, edgecolor='black', facecolor='yellow')

ax.add_patch(rec_a)
ax.add_patch(rec_b)
ax.add_patch(rec_c)
ax.add_patch(rec_d)
ax.add_patch(rec_e)

# plt.figure(figsize=(20,20))
plt.plot(20,20)
plt.show()

# fig = plt.figure() 
# ax = fig.add_subplot(111) 

# # 画矩形框
# currentAxis = plt.gca()  # 获取当前子图
# rect = patches.Rectangle((0,5),8,4, linewidth=2, edgecolor='r', facecolor='none')
# currentAxis.add_patch(rect)
# plt.show()