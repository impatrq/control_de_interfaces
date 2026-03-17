# Introducción

Creación de cuenta de github, primeros pasos: Repositorio y uso de Git.

## Creando cuenta de Git HUB 

- Crear un repositorio publico con el mismo nombre que tu usuario.
- Darle a la opcion de agregar un README.md

### Uso de Git

Una vez creado el repositorio vamos a clonarlo dentro de nuestra computadora usando la terminal:

1. Abrir la terminal/consola y dirigirse hacia /desktop/
2. Copiar la URL de nuestro repositorio
3. Clonar el repositorio con el siguiente comando:
```bash
git clone URL
```

De esta forma veremos que aparecerá como carpeta dentro de la computadora.

4. Abrir el archivo README.md en visual studio code y modificarlo 

<br>

---

Una vez modificado el archivo mandaremos los cambios a github utilizando la consola.

1. Primero tenemos que configurar nuestros datos, para eso:

```bash
git config user.email email@email.com
```

```bash
git config user.name "Nombre Apellido"
```

2. Luego, vamos a agregar a _git_ el o los archivos que modificamos en la actividad. Podemos verificar eso escribiendo:

```bash
git status
```

Para efectivamente agregar el cambio, vamos a escribir:

```bash
git add FILE
```

Reemplazando `FILE` por el nombre del archivo que corresponda. Si este paso trajo errores, es porque la ruta no coincide.

3. Vamos a hacer un commit para guardar el estado de nuestro repositorio. Para eso escribimos:

```bash
git commit -m "describo brevemente lo que hice"
```

Este mensaje debe ser corto pero dar informacion clara de que se hizo. Ejemplo: cambie el tiempo de demora a 200 ms.

4. Pusheamos los cambios a nuestro repositorio usando:

```bash
git push
```

## Modificando el README

Un README es una guia introductoria para todo repositorio, en este caso, este README aparecerá en tu perfil como un tipo de descripción corta o detallada sobre ti.

Estos documentos estan escritos utilizando [MARKDOWN](https://www.markdownguide.org/basic-syntax/)

Para armar tu presentación puedes escribir tu nombre, edad y diferentes datos ya sea lo que te gusta hacer, que te gustaria estudiar, alguna imagen de alguna serie que te guste, etc.

<br>


## Primeros pasos y entrega de actividades

La carpeta de la materia será completamente virtual, alojada en un repositorio: Control de Interfases, el cual será una [bifurcación](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) de este repo.

A partir de la actividad 1, deberán trabajar dentro de este directorio y subir a github los archivos una vez terminada la tarea, de la misma forma que hicimos con el README.

