import sys
#sys.path.append('module')
sys.path.insert(0,'module')
print(sys.path)
print('-'*50)
import my_module

my_module.test1()