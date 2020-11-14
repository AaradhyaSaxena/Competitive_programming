#### maths1

from fractions import Fraction as F

def gb(G, B):
    E = [[F(0, 1)] * (B+1) for _ in xrange(G+1)]
    for g in xrange(G+1):
        E[g][0] = F(g, 1)
    for b in xrange(1, B+1):
        for g in xrange(1, G+1):
            E[g][b] = max(0, (g * (E[g-1][b]+1) + b * (E[g][b-1]-1)) * F(1, (b+g)))
    for row in E:
        for v in row:
            print '%5.2f' % v,
        print
    print
    return E[G][B]

print gb(8, 10)

###


