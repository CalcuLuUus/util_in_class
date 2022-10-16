使用minimize.cpp得到DFA化简结果

## How to use it

在你使用它之前，你必须准备一些信息，比如

1. 你想输入state数

2. alphabet的大小($\sum$里有多少个)

3. 整张转移表的信息

4. final state和final state的数量

## Sample

以ppt为例子

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017021437.png"/>

那么个DFA的转移表如下所示

|     | 0   | 1   |
| --- | --- | --- |
| qe  | q0  | q1  |
| q0  | q00 | q01 |
| q1  | q10 | q11 |
| q00 | q00 | q01 |
| q01 | q10 | q11 |
| q10 | q00 | q01 |
| q11 | q10 | q11 |

这张表一共有7个state, final state为q11

那么我们得到的信息如下：

- 想输入的状态数：7

- alphabet的大小：2

- 整张转移表的信息

- final state和final state的数量：q11    1

按照程序提示输入信息

**注意：转移表的输入以空格分开，每个状态名在程序中用string存储，不能带空格**

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017022615.png"/>

程序的返回分3部分

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017024057.png"/>

1. 第一部分为每一个状态名称和对应的id，id用于第二部分

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017023338.png"/>

2. 第二部分为化简表格

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017024018.png"/>

状态数的id是从0开始标号的，假设一共有n个状态，化简表格的行标号从1到n-1，列标号从0到n-2，标号顺序符合老师上课所习惯的标号顺序（即先出现的状态id小）

我们看到，行1列0是O，代表id为1的状态和id为0的状态可以合并，根据第一部分可得知，即q0(id=1)和qe(id=0)可以合并，表格为X的就是不能合并

可以对照ppt的结果

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017023426.png"/>

3. 第三部分为附属部分，如果你发现程序的标号和你的表格顺序不一，不方便对照的时候，程序提供了另外一种对照办法。程序将可以合并的状态对一同输出出来，方便在id顺序和你标号不一样的时候查看

<img src="https://raw.githubusercontent.com/CalcuLuUus/pics/main/20221017023729.png"/>

这里提供了所有可以合并的状态对，即q0和qe可以合并，q00和qe可以合并等等，可以对照上述表格

如有问题可以issue或微信提问反馈
