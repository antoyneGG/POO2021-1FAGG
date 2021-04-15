class Estudiante:
    def __init__(self, nombre, empleid, documento, email, telefono, primera_matricula_periodo, primera_matricula):
        self.nombre = nombre
        self.empleid = empleid
        self.documento = documento
        self.email = email
        self.telefono = telefono
        self.primera_matricula_periodo = primera_matricula_periodo
        self.primera_matricula = primera_matricula
        self.estudiandoMaestria = False
        self.estudiandoEspecializacion = False
        self.especializacion = False
        self.periodo_grado_esp = ""
        self.maestria = False
        self.periodo_grado_maestria = ""
        self.primerMatricula = False
        self.linkedin = ""
        self.ultimoRol = ""
        self.nombreTrabajoGrado = ""
        self.anioSustentacion = ""
        self.nombreDirector = ""
    def setEsp(self, periodo_grado_esp):
        self.especializacion = True
        self.periodo_grado_esp = periodo_grado_esp
    def setMast(self, periodo_grado_maestria):
        self.maestria = True
        self.periodo_grado_maestria = periodo_grado_maestria
    def setPrimerPeriodoMatricula(self, primera_matricula_periodo, primera_matricula):
        self.primera_matricula_periodo = primera_matricula_periodo
        self.primera_matricula = primera_matricula
        self.primerMatricula = True
    def setEstudiandoMaestria(self, codigo):
        if(codigo == 0):
            self.estudiandoMaestria = False
        else:
            self.estudiandoMaestria = True
    def setEstudiandoEspecializacion(self, codigo):
        if(codigo == 0):
            self.estudiandoEspecializacion = False
        else:
            self.estudiandoEspecializacion = True
    def setTrabajoGrado(self, nombreTrabajoGrado, anioSustentacion, nombreDirector):
        self.nombreTrabajoGrado = nombreTrabajoGrado
        self.anioSustentacion = anioSustentacion
        self.nombreDirector = nombreDirector
    def setLinkedinUltimoRol(self, linkedin, ultimoRol):
        self.linkedin = linkedin
        self.ultimoRol = ultimoRol
