def getEscapeTime(complex c):
    cdef complex z = 0
    cdef int i
    for i in range(200):
        if z.real * z.real + z.imag * z.imag > 4:
            return i
        z = z*z + c
    return  i
