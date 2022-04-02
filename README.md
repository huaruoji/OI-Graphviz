~~我才不会告诉你这个垃圾 repo 是用来学 git 和 python 的~~

# OI-Graphviz

## 介绍

OI 中一点实用的 Graphviz 画图工具。

有 Python 版本和 C++ 版本。C++ 版本不再维护，但基础的东西（加边，生成 dot 文件和图片）能用（早知道 Python 有写好的 Graphviz 库我为什么要用 C++ 搞啊）。

使用前请确保您已经安装了 Graphviz。

## 使用指南

Python 文件夹的结构如下：

```text
Python:
├─test
└─graph
```

### test

`test` 目录里有一点测试用程序，属于是杂物。

### graph

`graph` 目录里的 `graph.py` 从同目录下的 `graph.in` 读取输入数据，并生成一张图。输入数据可选有向图或无向图，并支持是否带边权。

`graph.in` 的格式如下：

```text
tp1 tp2
n m
u1 v1 (w1)
u2 v1 (w2)
...
um vm (wm)
```

`tp1` 为 `1` 表示输入有向图，为 `0` 表示输入无向图。`tp2` 为 `1` 表示有边权，为 `0` 表示无边权。然后输入 `n`，`m` 表示图的点数和边数。接着输入 `m` 条边，每行 2 个数表示边的 2 个端点。如果选择带边权则每行输入 3 个数，第 3 个数表示边权。