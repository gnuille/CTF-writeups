import itertools
import hashlib

ll = ['s','f','g','c','m','S','F','G','C','M','1','3','5','0','!','%','=']
# sha = 'f3d67947c97a01e3077c3e41c3002ae71d22b32a'
sha = 'b8e46064c5cb98321ab378f546d2641881b43563'

for L in range (0, len(ll)+1):
    print "Mida: " + str(L)
    for subset in itertools.permutations(ll, L):
        if (hashlib.sha1(''.join(subset)).hexdigest() == sha):
            print ''.join(subset)

