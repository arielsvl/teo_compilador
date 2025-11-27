# 📘 Proyecto: Lenguaje DSL *Freakiemore* y Compilador para Carro Seguidor de Línea

## 👥 Integrantes del Equipo

| Nombre | Carnet |
|--------|--------|
| **Claudia María Chávez Grande** | 00037221 |
| **Rodrigo Orlando Zepeda Ramos** | 00175520 |
| **Alan Ariel Flores Martinez** | 00019420 |
| **Carlos Antonio Marroquín Carballo** | 00025221 |

---

## 📝 Descripción del Proyecto

Este proyecto consiste en el diseño y la construcción de un **lenguaje de programación específico del dominio (DSL)** llamado **Freakiemore**, orientado al control de un **carro seguidor de línea**. Incluye el desarrollo completo del **compilador**, su **analizador léxico**, **analizador sintáctico**, **analizador semántico**, y la implementación de una **máquina abstracta** que permite ejecutar las instrucciones generadas.

El trabajo integra conceptos esenciales de:

- Gramáticas formales  
- Análisis léxico, sintáctico y semántico  
- Generación de código intermedio  
- Diseño de compiladores  
- Sistemas embebidos  
- Ejecución en máquina virtual personalizada  

También se construyó y evaluó un prototipo físico del carro, validando experimentalmente que las instrucciones del lenguaje correspondieran a comportamientos reales y consistentes.

Este proyecto demuestra la viabilidad de unir teoría de lenguajes, compiladores y hardware en un mismo sistema funcional.

---

## 📂 Contenido del Repositorio

El repositorio contiene:

- Código fuente del lenguaje y compilador (Flex, Bison, C)
- Implementación de la máquina virtual
- Archivos del AST y módulos semánticos
- Programas de prueba para validar el compilador
- Documentación complementaria y diagramas

---

## 🚗 ¿Qué es Freakiemore?

Freakiemore es un DSL diseñado para controlar un carro seguidor de línea mediante instrucciones simples y expresivas como:

```txt
move(50);
turnLeft(90);
if (read(sensorIzq) == true) { ... }
