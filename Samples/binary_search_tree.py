#coding=utf-8

class Node(object):
    """节点类"""
    def __init__(self, elem=-1, lchild=None, rchild=None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild

class BSTree(object):
    def __init__(self):
        self.root = Node() # Initialize with root node

    def add(self, data):
        node = Node(data)
        