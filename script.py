# /usr/bin/env python3


import os
import re
import urllib.parse

class Dir(object):
    def __init__(self, path, dir_name):
        self.subDirs = []
        self.files = []
        root = os.getcwd()
        
        for dir in os.listdir(path):
            str = "+ [" + dir.rstrip('.md') + "]" + "(./" + dir_name + "/" + urllib.parse.quote(dir) + ")"
            print(str)
            



def main():
    root = os.getcwd()
    # print( current_dir )
    for dir in sorted(os.listdir(root)):
        if not dir.startswith(".") and os.path.isdir(dir):            
            if "-" in dir:
                print( "\n## " + dir.split("-")[1] )
            else:
                print( "\n## " + dir)

            path = os.path.join(root, dir)
            Dir(path, dir)
            # print(path)
            
            
            




if __name__ == '__main__':    
    main()