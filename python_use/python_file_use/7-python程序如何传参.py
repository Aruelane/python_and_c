
import sys


# print(type(sys.argv))
#print(sys.argv)
def write_hello(file_path):
    file = open(file_path, 'w+', encoding='utf8')
    file.write('hello')
    file.close()


if __name__ == '__main__':
    print(sys.argv)
    write_hello(sys.argv[1])#直接运行错误是因为没有传递参数，在运行编辑配置中添加参数即可