from math import pi, cos, sin, sqrt

class Shape:
    def __init__(self):
        self.__vertices = []
        self.__center = (0,0)
    def __str__(self):
        res = ""
        for vertex in self.__vertices:
            x, y = vertex
            res += f"X: {x} | Y: {y}\n"
        return res
    def getVertices(self): return self.__vertices
    def getCenter(self): return self.__center
    def __setVertices(self, newValue): self.__vertices = newValue
    def __setCenter(self, newValue): self.__center = newValue
    Vertices = property(lambda x : x.__vertices, __setVertices)
    Center = property(lambda x : x.__center, __setCenter)

class Circle (Shape):
    def __init__(self, pos, radius, resolution):
        Shape.__init__(self)
        self.Center = pos
        self.__radius = radius
        vertices = []
        for i in range(0, resolution):
            angle = i/resolution * 2 * pi

            vertices.append((pos[0] + radius * cos(angle),
                                    pos[1] + radius * sin(angle)))
        self.Vertices = vertices
    def getRadius(self): return self.__radius
    def getArea(self): return pi * self.__radius**2
    def getLength(self): return 2 * pi * self.__radius

class Rectangle (Shape):
    def __init__(self, vertices):
        Shape.__init__(self)
        self.Vertices = vertices
        x, y = 0, 0
        for vertex in vertices:
            x += vertex[0]
            y += vertex[1]
        self.Center = (x,y)
    def getArea(self):
        x = self.Vertices[1][0] - self.Vertices[0][0]
        y = self.Vertices[1][1] - self.Vertices[0][1]

        area = sqrt(x**2 + y**2)

        x = self.Vertices[2][0] - self.Vertices[1][0]
        y = self.Vertices[2][1] - self.Vertices[1][1]

        return area * sqrt(x**2 + y**2)
    def getLength(self):
        length = 0

        for i in range(0,2):
            x = self.Vertices[i + 1][0] - self.Vertices[i][0]
            y = self.Vertices[i + 1][1] - self.Vertices[i][1]

            length += sqrt(x**2 + y**2)
        return length * 2
    
class Square (Rectangle):
    def __init__(self, vertices):
        Rectangle.__init__(self, vertices)
    def getLength(self):
        return sqrt(self.Vertices[0][0]**2 + self.Vertices[0][1]**2) * 4