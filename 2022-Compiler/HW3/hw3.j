.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
ldc 11
istore 0
iload 0
0: L_case_0
L_case_0:
goto L_switch_end_-1
ldc A
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
1: L_case_1
L_case_1:
goto L_switch_end_-1
ldc B
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
2: L_case_2
L_case_2:
goto L_switch_end_-1
ldc C
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
3: L_case_3
L_case_3:
goto L_switch_end_-1
ldc D
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
default: L_case_4
L_switch_end_-1:
return
goto L_switch_begin_0:
L_switch_begin_0
lookupswitch
iload 0
0: L_case_0
L_case_0:
goto L_switch_end_0
ldc A
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
1: L_case_1
L_case_1:
goto L_switch_end_0
ldc B
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
2: L_case_2
L_case_2:
goto L_switch_end_0
ldc C
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
3: L_case_3
L_case_3:
goto L_switch_end_0
ldc D
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
default: L_case_4
L_switch_end_0:
return
goto L_switch_begin_1:
L_switch_begin_1
lookupswitch
return
.end method
