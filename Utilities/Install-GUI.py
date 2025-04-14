import tkinter as tk
import sys

route = tk.Tk()
route.title("BE3D Utility")
route.geometry("120x120")
bar = tk.menu(route)

def CheckUpdates():
    print("Checking Updates")

def VersionInfo():
    print("Version Info")

def Exit():
    route.quit()

App_b = tk.Menu(bar, tearoff=0)
App_b.add_command(label="", command=Exit)

update_b = tk.Menu(bar, tearoff=0)
update_b.add_command(label="Check for Updates", command=CheckUpdates)
update_b.add_command(label="Current Version", command=VersionInfo)
update_b.add_separator()

project_b = tk.Menu(bar, tearoff=0)
project_b.add_command(label="New", command=new_file)

menu_bar.add_cascade(label="Application", menu=App_b)
menu_bar.add_cascade(label="Update", menu=update_b)
menu_bar.add_cascade(label="Projects", menu=project_b)

root.config(menu=menu_bar)
route.mainloop()