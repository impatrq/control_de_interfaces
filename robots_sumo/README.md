Carpeta designada para robot -nombre-


-----------------------------------------


## ¿Cómo clonar una sola rama de un repositorio de GitHub?

Este ejemplo lo haremos clonando y modificando la rama de `firmware`. A la hora de replicarlo, modificar esta palabra por el nombre de la rama que estén trabajando.
#### 1. Clonar el repositorio

Reemplazar `<URL_DEL_FORK>` por la URL del fork del repositorio del equipo.
```bash
git clone <URL_DEL_FORK>
```
Ingresar al directorio que acabamos de clonar `control_de_interfaces`
```bash
cd control_de_interfaces
```
Ingresar al directorio del proyecto.

```bash
cd robots_sumo
```

#### 2. Ver las ramas disponibles

```bash
git branch -a
```

#### 3. Cambiar a la rama de trabajo

Por ejemplo, para trabajar sobre la rama `firmware`:
```bash
git switch firmware
```
Para verificar en qué rama estoy:

```bash
git branch
```
La rama activa aparecerá marcada con un `*`.

#### 4. Actualizar la rama antes de comenzar

Antes de realizar modificaciones, descarmos los últimos cambios del repositorio.

```bash
git pull origin firmware
```
------------------------------------------
### Ahora podemos realizar las modificaciones que querramos, pero únicamente en los archivos que correspondan a esta rama de trabajo, y luego debemos subir todos los cambios

#### 1. Configuramos nuestros datos:

```bash
git config user.email email@email.com
```

```bash
git config user.name "Nombre Apellido"
```

#### 2. Verificar los cambios (al principio aparecerán en rojo)
```bash
git status
```
#### 3. Agregar los archivos modificados
```bash
git add .
```
#### 4. Verficar los cambios (ahora aparecerán en verde)
```bash
git status
```

#### 5. Crear un commit
```bash
git commit -m "Describo brevemente los cambios"
```
#### 6. Subir los cambios a GitHub
```bash
git push origin firmware
```
