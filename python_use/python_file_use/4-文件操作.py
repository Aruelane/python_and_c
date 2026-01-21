
# 'r' 模式：只读模式，文件必须存在，不能写入
# 'w' 模式：写入模式，如果文件存在会覆盖文件内容，如果文件不存在则会创建新文件
# 'a' 模式：追加模式，向文件末尾添加内容，如果文件不存在则会创建新文件
# 'r+' 模式：读写模式，文件必须存在，可以读也可以写
# 'w+' 模式：读写模式，文件存在时会覆盖文件内容，如果文件不存在则会创建新文件
# 'a+' 模式：读写模式，可以读取和追加内容
# 'rb' 模式：二进制只读模式，读取二进制文件
# 'wb' 模式：二进制写入模式，写入二进制文件
# 'ab' 模式：二进制追加模式，向二进制文件末尾添加内容

# 'read(size=-1)'：读取文件内容，如果 size 为负值或未指定，读取整个文件内容
# 'readline(size=-1)'：读取文件的一行，可以指定 size 参数来控制读取的字节数
# 'readlines(hint=-1)'：读取文件的所有行，并返回一个列表，可以指定 hint 参数来读取指定数量的字节
# 'write(string)'：将字符串写入文件，如果文件模式为 'w' 或 'w+'，会覆盖文件内容
# 'writelines(lines)'：写入多个行到文件，lines 为一个可迭代对象，通常是字符串列表
# 'seek(offset, whence=0)'：移动文件指针到指定位置，offset 为偏移量，whence 用来指定偏移的基准位置
# 'tell()'：返回当前文件指针的位置


def open_r():
    """
    读取文件
    :return:
    """
    file = open('file2.txt', mode='r', encoding='utf-8')
    text = file.read()  # 读出来都是字符串
    print(text)
    file.close()


def open_rw():
    """
    读取文件,写文件
    :return:
    """
    file = open('file2.txt', mode='r+', encoding='utf-8')
    text = file.read()  # 读出来都是字符串
    print(text)
    file.write('world')  # 写到末尾了
    file.close()


def open_w():
    """
    练习w模式
    :return:
    """
    file = open('file9', mode='w', encoding='utf-8')  # 文件不存在就会创建，存在就会清空
    file.write('hello！gogogo！！！')
    file.close()


def open_a():
    """
    练习a模式，每次写的时候写到文件末尾
    :return:
    """
    file = open('file1', mode='a', encoding='utf-8')
    file.write('howdayday')  # 使用r+模式，打开后在开头，内容直接覆盖
    file.close()


def use_readline():
    # 打开文件
    file = open("file2.txt", encoding='utf8')

    while True:
        # 读取一行内容
        text = file.readline()

        # 判断是否读到内容,读取到文件末尾拿到的是一个空字符串
        if not text:
            break

        # 每读取一行的末尾已经有了一个 `\n`
        print(text, end="")
def my_use_readline():
    file = open("file2.txt", encoding='utf8')
    text = file.readline(-1)
    print(text, end="")
    text = file.readline(-1)
    print(text, end="")


    # 关闭文件
    file.close()


if __name__ == '__main__':
    #open_r()
    #open_rw()
    #open_w()
    #open_a()
    use_readline()
    print('\n','-'*50)
    my_use_readline()
