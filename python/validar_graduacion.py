from estudiante import Estudiante
import json
import glob
import pyexcel as p
from pyexcel._compact import OrderedDict
from pyexcel.cookbook import split_a_book
from pyexcel.cookbook import merge_all_to_a_book

listaEstudiantes = []
cantPersonasGraduadasEsp = 0
cantPersonasGraduadasMast = 0
cantPersonasGraduadasEspMast = 0
cantPersonasGraduadasEspMastEnCurso = 0
cantPersonasSustentacion = 0
cantPersonasPendientesEsp = 0
cantPersonasPendientesMast = 0
cantPersonasMatriculaEsp = 0
cantPersonasMatriculaMast = 0

def recolectarInformacionEstudiantes():
    global cantPersonasGraduadasEsp
    global cantPersonasGraduadasMast
    global cantPersonasGraduadasEspMast
    global cantPersonasGraduadasEspMastEnCurso
    global cantPersonasSustentacion
    global cantPersonasPendientesEsp
    global cantPersonasPendientesMast
    global cantPersonasMatriculaEsp
    global cantPersonasMatriculaMast
    cel = ''
    split_a_book("ConsolidadoEstudiantes-Graduados20162_a_20202.xlsx", "output.xlsx")
    outputfiles = glob.glob("*_output.xlsx")
    for file in sorted(outputfiles):
        print(file + "\n")
        records = p.get_records(file_name = file)
        for r in records:
            evaluar = False
            if 'Emplid' in r and 'Nombres' in r and 'Documento' in r and 'Email' in r and ('Teléfono Permanente' in r or 'Teléfono Celular' in r):
                if(r['Teléfono Permanente'] == ""):
                    cel = 'Teléfono Celular'
                else:
                    cel = 'Teléfono Permanente'
                for est in listaEstudiantes:
                    if(r['Emplid'] == est.empleid):
                        evaluar = True
                        if(r['Código'] == "20005"):
                            est.setEstudiandoMaestria(1)
                        elif(r['Código'] == "20007"):
                            est.setEstudiandoEspecializacion(1)
                if(not evaluar):
                    estudiante = Estudiante(r['Nombres'],r['Emplid'],r['Documento'],r['Email'],r[cel],r['Periodo'])
                    if(r['Código'] == "20005"):
                        estudiante.setEstudiandoMaestria(1)
                    elif(r['Código'] == "20007"):
                        estudiante.setEstudiandoEspecializacion(1)
                    listaEstudiantes.append(estudiante)

    for est in listaEstudiantes:
        if(est.estudiandoMaestria):
            cantPersonasMatriculaMast += 1
        if(est.estudiandoEspecializacion):
            cantPersonasMatriculaEsp += 1

    graduadosMast = p.get_records(file_name = 'GraduadosMaestria_output.xlsx')
    for g in graduadosMast:
        for est in listaEstudiantes:
            if(g['Nombre'] == est.nombre):
                est.setMast(g['Periodo'])
                est.setLinkedinUltimoRol(g['Linkedin'],g['Ultimo rol'])
                est.setEstudiandoMaestria(0)
                cantPersonasGraduadasMast += 1

    graduadosEsp = p.get_records(file_name = 'GraduadosEspecializacion_output.xlsx')
    for g in graduadosEsp:
        for est in listaEstudiantes:
            if(g['Nombre'] == est.nombre):
                est.setEsp(g['Periodo'])
                est.setLinkedinUltimoRol(g['Linkedin'],g['Ultimo rol'])
                est.setEstudiandoEspecializacion(0)
                cantPersonasGraduadasEsp += 1
                if(est.estudiandoMaestria):
                    cantPersonasGraduadasEspMastEnCurso += 1
                elif(est.maestria):
                    cantPersonasGraduadasEspMast += 1

    trabajosGrado = p.get_records(file_name = 'ACTAS_de_sustentaciones_de_Maestria_en_Ingenieria_anteproyectos_y_trabajos_de_grado.xlsx', start_row = 5)
    for t in trabajosGrado:
        for est in listaEstudiantes:
            if(est.documento == str(t['DOCUMENTO'])):
                est.setTrabajoGrado(t['TÍTULO'],t['FECHA'],t['DIRECTOR'])
                cantPersonasSustentacion += 1

    for est in listaEstudiantes:
        if(est.estudiandoMaestria):
            cantPersonasPendientesMast += 1
        if(est.estudiandoEspecializacion):
            cantPersonasPendientesEsp += 1

def guardarInformacion():
    dict_estudiantes = OrderedDict()

    dict_estudiantes.update({"Emplid": []})
    dict_estudiantes.update({"Nombre": []})
    dict_estudiantes.update({"Documento": []})
    dict_estudiantes.update({"Email": []})
    dict_estudiantes.update({"Telefono": []})
    dict_estudiantes.update({"Primera matricula": []})
    dict_estudiantes.update({"Graduado especializacion": []})
    dict_estudiantes.update({"Periodo grado especializacion": []})
    dict_estudiantes.update({"Graduado maestria": []})
    dict_estudiantes.update({"Periodo grado maestria": []})
    dict_estudiantes.update({"Linkedin": []})
    dict_estudiantes.update({"Ultimo rol": []})
    dict_estudiantes.update({"Trabajo de grado": []})
    dict_estudiantes.update({"Año de sustentacion": []})
    dict_estudiantes.update({"Director": []})
    dict_estudiantes.update({"Pendiente de especializacion": []})
    dict_estudiantes.update({"Pendiente de maestria": []})

    dato = ""
    for key in dict_estudiantes.keys():
        lista = []
        for estudiante in listaEstudiantes:
            if(key == "Emplid"):
                dato = estudiante.empleid
            elif(key == "Nombre"):
                dato = estudiante.nombre
            elif(key == "Documento"):
                dato = estudiante.documento
            elif(key == "Email"):
                dato = estudiante.email
            elif(key == "Telefono"):
                dato = estudiante.telefono
            elif(key == "Primera matricula"):
                dato = estudiante.primera_matricula_periodo
            elif(key == "Graduado especializacion"):
                if(estudiante.especializacion):
                    dato = "Si"
                else:
                    dato = "No"
            elif(key == "Periodo grado especializacion"):
                dato = estudiante.periodo_grado_esp
            elif(key == "Graduado maestria"):
                if(estudiante.maestria):
                    dato = "Si"
                else:
                    dato = "No"
            elif(key == "Periodo grado maestria"):
                dato = estudiante.periodo_grado_maestria
            elif(key == "Linkedin"):
                dato = estudiante.linkedin
            elif(key == "Ultimo rol"):
                dato = estudiante.ultimoRol
            elif(key == "Trabajo de grado"):
                dato = estudiante.nombreTrabajoGrado
            elif(key == "Año de sustentacion"):
                dato = estudiante.anioSustentacion
            elif(key == "Director"):
                dato = estudiante.nombreDirector
            elif(key == "Pendiente de especializacion"):
                if(estudiante.estudiandoEspecializacion):
                    dato = "Si"
                else:
                    dato = "No"
            elif(key == "Pendiente de maestria"):
                if(estudiante.estudiandoMaestria):
                    dato = "Si"
                else:
                    dato = "No"
            lista.append(dato)
        dict_estudiantes[key] = lista

    p.save_as(adict=dict_estudiantes, dest_file_name='estudiantes_merge.xlsx')

    resumen = [["Detalle", "Dato"], ["Cantidad de personas que se han graduado solo de la especializacion a la fecha", cantPersonasGraduadasEsp], ["Cantidad de personas que se han graduado solo de la maestria a la fecha", cantPersonasGraduadasMast], ["Cantidad de personas que ya se han graduado de especializacion y maestria", cantPersonasGraduadasEspMast], ["Cantidad de personas de la maestria que han optado por el grado de especialistas pero no se han graduado todavia", cantPersonasGraduadasEspMastEnCurso], ["Cantidad de personas que han sustentado el trabajo de grado", cantPersonasSustentacion], ["Cantidad de personas pendientes por grado de especializacion", cantPersonasPendientesEsp], ["Cantidad de personas pendientes por tesis de maestria", cantPersonasPendientesMast], ["Cantidad de personas que han matriculado especializacion", cantPersonasMatriculaEsp], ["Cantidad de personas que han matriculado maestria", cantPersonasMatriculaMast]]
    p.save_as(array = resumen, dest_file_name="resumen_merge.xlsx")

    merge_all_to_a_book(glob.glob("*_merge.xlsx"), "Datos_Especializacion_Maestria.xlsx")

def main():
    recolectarInformacionEstudiantes()
    guardarInformacion()

main()
    