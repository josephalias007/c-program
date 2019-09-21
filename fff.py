import numpy as np
import matplotlib.pyplot as plt


def line_gen(A,B):
  len =10
  x_AB = np.zeros((2,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB




x = np.linspace(-9, 9, 400)
y = np.linspace(-5, 5, 400)
x, y = np.meshgrid(x, y)

def axes():
    plt.axhline(0, alpha=.1)
    plt.axvline(0, alpha=.1)
    
    
a=np.loadtxt("./data/zx.dat",dtype='float')
b=np.loadtxt("./data/zy.dat",dtype='float')


p=np.zeros(2)
p=np.loadtxt("./data/zg.dat",dtype='float')
print(p)

s=np.zeros(2)
s=np.loadtxt("./data/zl.dat",dtype='float')
print(s)



x_AB = line_gen(p,s)
plt.plot(x_AB[0,:],x_AB[1,:],label= "$AB$")
plt.plot(p[0], p[1], 'o')
plt.text(p[0] * (1 - 0.2), p[1] * (1 + 0.1) , 'P')

plt.plot(s[0], s[1], 'o')
plt.text(s[0] * (1 - 0.2), s[1] * (1 + 0.1) , 'A')





axes()
plt.contour(x, y,(x**2/a**2 + y**2/b**2), [1], colors='k')
plt.grid()
plt.show()
