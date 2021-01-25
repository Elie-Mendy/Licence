#!/usr/bin/python3
# coding: utf-8

""" exemple d'execution du programme cité dans le chapitre 1 """

v_2999 = 1
v_3000 = 0
v_3001 = 1

for i in range(50):
    v_3002 = v_3000 + v_3001
    v_3000 = v_3001 / v_2999
    v_3001 = v_3002 / v_2999
    #print("v_2999 = {}\nv_3000 = {}\nv_3001 = {}\nv_3002 = {}\n")
    print(v_3000)
