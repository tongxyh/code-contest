#coding=utf-8
class Node(object):
    """节点类"""
    def __init__(self, elem=-1, lchild=None, rchild=None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild

def preTraverse(root):  
    if root==None:  
        return  
    print(root.value)  
    preTraverse(root.left)  
    preTraverse(root.right)  
  
def midTraverse(root):  
    if root==None:  
        return  
    midTraverse(root.left)  
    print(root.value)  
    midTraverse(root.right)  
  
def afterTraverse(root):  
    if root==None:  
        return  
    afterTraverse(root.left)  
    afterTraverse(root.right)  
    print(root.value) 