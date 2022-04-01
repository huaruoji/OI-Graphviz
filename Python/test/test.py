import graphviz
import os
output_file_name = 'test'
dot = graphviz.Digraph(format='png', name=output_file_name)
dot.attr('graph', dpi='300')
dot.node('A', 'sth')
dot.node('B', 'sth2')
dot.node('C', 'wtf')
dot.edges(['AB', 'BC', 'CA'])
print(dot.source)
file_directory = os.path.split(__file__)[0]
dot.render(directory=file_directory).replace('\\', '/')
