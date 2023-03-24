conj1 = set()
conj1.add(1)
conj1.add(2)
conj1.add(3)
conj1.add(4)

print(conj1)

conj2 = set()
conj2.add(1)
conj2.add(3)
conj2.add(5)
conj2.add(7)
conj2.add(7)

print(conj2)

print(conj2.difference(conj1))