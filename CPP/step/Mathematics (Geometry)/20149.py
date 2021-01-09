Ax, Ay, Bx, By = map(float, input().split())
Cx, Cy, Dx, Dy = map(float, input().split())

def CCW(A, B, C):
    X1 = B[0] - A[0]; X2 = C[0] - A[0]
    Y1 = B[1] - A[1]; Y2 = C[1] - A[1]

    result = X1 * Y2 - X2 * Y1
    return -1 if result > 0 else 1 if result < 0 else 0

def getPoint(A, B, C, D):
    X = [A[1]-B[1], B[0]-A[0], A[0]*B[1]-A[1]*B[0]]
    Y = [C[1]-D[1], D[0]-C[0], C[0]*D[1]-C[1]*D[0]]
    Cross = [X[1]*Y[2]-X[2]*Y[1], X[2]*Y[0]-X[0]*Y[2], X[0]*Y[1]-X[1]*Y[0]]
    print(Cross[0] / Cross[2], Cross[1] / Cross[2])

A = [Ax, Ay]; B = [Bx, By]; C = [Cx, Cy]; D = [Dx, Dy]

t0 = CCW(A, B, C) * CCW(A, B, D)
t1 = CCW(C, D, A) * CCW(C, D, B)

if t0 == 1 or t1 == 1:
    print(0)
elif t0 == 0 and t1 == 0:
    if A >= B:
        A, B = B, A
    if C >= D:
        C, D = D, C
    if D >= A and B >= C:
        print(1)
        if B == C:
            print(*B)
        elif not(CCW(A, B, C) == 0 and CCW(A, B, D) == 0):
            getPoint(A, B, C, D)
    else:
        print(0)
else:
    print(1)
    getPoint(A, B, C, D)
