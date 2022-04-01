import graphviz
import os


def main_work():  # 在这里做最主要的工作
  n, m = f.readline().split()
  n = int(n)
  m = int(m)
  for i in range(m):
    if(weight == 0):
      u, v = f.readline().split()
      if(tp == 0):
        dot.edge(u, v, dir='none')
      else:
        dot.edge(u, v)
    else:
      u, v, w = f.readline().split()
      if(tp == 0):
        dot.edge(u, v, dir='none', label=w)
      else:
        dot.edge(u, v, label=w)


def init():
  global dot, tp, weight
  output_file_name = 'graph'
  tp, weight = f.readline().split()
  tp = int(tp)
  weight = int(weight)
  dot = graphviz.Digraph(format='png', name=output_file_name)
  dot.attr('graph', dpi='300')


def print_graph():
  # print(dot.source)
  dot.render(directory=file_directory).replace('\\', '/')


def main():
  global f, file_directory
  file_directory = os.path.split(__file__)[0]
  os.chdir(file_directory)
  f = open('graph.in', 'r')
  init()
  main_work()
  print_graph()
  f.close()


main()
