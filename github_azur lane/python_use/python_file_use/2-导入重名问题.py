
from module1 import test1
from module2 import test1 as module2_test1
import random

test1()
module2_test1()

print(random.__file__) #查看模块所在路径,是random.py文件，即random模块的源代码文件
a=random.randint(1,10)#返回一个随机整数，包括1和10
print(a)
