class Person:
    classvar = "NICE"
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    def __str__(self):
        return f"I am {self.name}, {self.age} years old"
    
    def voter(self):
        return self.age >= 18

Me = Person("Mushfiq", 23)

print(Me)
print(Me.voter())

Person.classvar = "NIKE"