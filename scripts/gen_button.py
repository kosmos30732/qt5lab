import csv
import sys
#from pathlib import Path
f=open(sys.argv[1])
r=csv.reader(f)
next(r)

btn_names=[]
btn_texts=[]
btn_geometries=[]

for row in r:
    btn_names+=[row[0]]
    btn_texts+=[row[1]]
    btn_geometries+= [','.join(row[2:])]

names_btn=''
for btn_name in btn_names:
    names_btn+='*{}, '.format(btn_name)
names_btn=names_btn[:len(names_btn)-2]
names_btn+=';'

btn_blocks=''
for btn_name,btn_text,btn_geometry in zip(btn_names,btn_texts,btn_geometries):
    btn_blocks+='{}= new QPushButton("{}", parent);\n\t\t{}->setGeometry({});\n\t\t'.format(btn_name,btn_text[1:],btn_name,btn_geometry[1:])

Button_MainWindow='''#include <QPushButton>

class Buttons_MainWindow
{{
public:
	QPushButton {}

    explicit Buttons_MainWindow(QWidget* parent)
    {{
        {}
    }};

    ~Buttons_MainWindow()
    {{

    }};
}};
'''
f_w=open(sys.argv[2],"tw")
f_w.write(Button_MainWindow.format(names_btn, btn_blocks))
f_w.close()

