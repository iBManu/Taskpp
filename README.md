# Autotask
## EN | English

**Autotask** is a command line program that automates the repetition of various commands through the creation of tasks.
### Installation

You have two installation options. You can download the source code and compile it, or you can download the pre-compiled program. If you download the pre-compiled program, skip to step 5.

1. Download the cpp file.

2. Open a console in the folder where the file is located.

3. Execute the following command (You need to have MinGW installed, you can download it from the following link): https://sourceforge.net/projects/mingw/
```
g++ -o autotask .\autojob.cpp
or
gcc -o autotask .\autojob.cpp
```

4. Now you should have an autojob.exe file.

5. On the D:/ drive, create a folder called 'Autotask' and place the autotask.exe executable in it.

6. Configure Autotask in the Path environment variable:
  - Open 'Edit the system environment variables' in the Windows Control Panel.
  - Click on the 'environment Variables...' button.
  - There should be an environment variable named Path, click on it.
  - Click 'New' and add the D:\Autotask directory.

7. You now have everything set up, and typing `autotask` in any system console should launch the program.

### Use guide

**Autotask** operates through the passing of commands and parameters. Using the command `autotask help`, you will receive a list with brief information about each of them. Here's a guide with more detailed information:

* `autotask add "name" ["description"]`: This command allows you to add a task with the specified name and description(optional). It then opens a text editor for you to add the desired commands. Example: `autotask add task1 This is the number 1 task`

* `autotask run "name"`: With this command, you execute the task with the specified name. Example: `autotask run task1`

* `autotask remove "name"`: You can use this command to delete the task with the specified name. Example: `autotask remove task1`

* `autotask edit "name"`: This command opens the task with the specified name in a text editor for modification. Example: `autotask edit task1`

* `autotask list`: This command displays a list of all available tasks.

* `autotask help`: This command provides a list of the program's commands and their usage.

* `autotask version`: This command retrieves the version of **Autotask** that you have installed.

* `autotask info`: This command provides some information about **Autotask**.

### Use example

I will create a task to automate working with React Native, which involves opening Visual Studio Code, Android Studio, and starting the Expo server. Here are the steps:

* Execute the command `autotask run ReactNativeSetUp This task sets up the environment for working with React Native`.

* Next, in the text editor, add the following commands:

```
call code .
call start "" "C:\Program Files\Android\Android Studio\bin\studio64.exe"
call expo start
```

* Now, whenever you want to work on a React Native project, simply run `autotask run ReactNativeSetUp` in your project folder, and everything will be done automatically.

### Recommendations

* It is advisable that each command within a task is preceded by call. This is due to how Windows executes various commands through batch files.
* To run a specific program, you should write `call start "" "programPath"`.

---

## ES | Español

**Autotask** es un programa de linea de comandos que automatiza la repetición de varios comandos a través de la creación de tareas.

### Instalación

Tienes dos opciones de instalación. Puedes descargar el codigo fuente y compilarlo o puedes descargar el programa ya compilado. Si descargas el programa ya compilado, salta hasta el punto 5.

1. Descarga el archivo cpp.
   
2. Abre una consola en la carpeta donde esté el archivo.
   
3. Ejecuta el siguiente comando (Necesitas tener instalado MinGW, puedes descargarlo en el siguiente enlace): https://sourceforge.net/projects/mingw/
```
g++ -o autotask .\autojob.cpp
o
gcc -o autotask .\autojob.cpp
```

4. Ahora deberías tener un archivo autojob.exe.
  
5. En el disco D:/ crea una carpeta llama 'Autotask', coloca ahí el ejecutable autotask.exe.
  
6. Configura autotask en la variable de entorno Path:
   - Abre `Editar variables de entorno` en el Panel de Control de Windows.
   - Clic en el botón `variables de entorno...`.
   - Debería aparecer una varible de entorno llamada Path, clic en ella.
   - Clic en `Nuevo` y añade la dirección D:\Autotask.

7. Ya tienes todo configurado y escribiendo `autotask` en cualquier consola del sistema debería iniciarse el programa.

 ### Guía de uso

Autotask funciona a través del paso de comandos y parametros, con el comando ```autotask help``` tendrás una lista con breve información de cada uno de ellos, aquí te dejo una guía con algo más de información:

* `autotask add "nombre" ["descripción"]`: Con este comando añades una tarea con el nombre y descripción indicados, a continuación se abre un editor de texto para añadir los comandos que quieras. Ejemplo: `autotask add tarea1 Esta es la tarea numero 1`

* `autotask run "nombre"`: Con este comando ejecutas la tarea con el nombre indicado. Ejemplo: `autotask run tarea1`

* `autotask remove "nombre"`: Con este comando eliminas la tarea con el nombre indicado. Ejemplo: `autotask remove tarea1`

* `autotask edit "nombre"`: Con este comando se abre la tarea con el nombre indicado en el editor de texto para ser modificada. Ejemplo: `autotask edit tarea1`

* `autotask list`: Con este comando muestras una lista con todas las tareas disponibles.

* `autotask help`: Con este comando obtienes una lista de los comandos del programa y su uso.

* `autotask version`: Con este comando obtienes la versión de **Autotask** que tienes instalada.

* `autotask info`: Con este comando obtienes algo de información sobre **Autotask**.

 ### Ejemplo de uso

Crearé una tarea para automatizar el trabajo con React Native, en este caso, quiero que abra el editor Visual Studio Code, Android Studio y que inicie el servidor de Expo, para ello haré lo siguiente.

* Ejecuto el comando `autotask run ReactNativeSetUp Esta tarea prepara el entorno para trabajar con React Native`

* A continuación, en el editor de texto añado los siguientes comandos.
```
call code .
call start "" "C:\Program Files\Android\Android Studio\bin\studio64.exe"
call expo start
```

* Ahora cada vez que quiera trabajar en algún proyecto con React Native, simplemente ejecuto `autotask run ReactNativeSetUp` en la carpeta de mi proyecto y todo se hará automáticamente.

 ### Recomendaciones

 * Cada comando dentro de una tarea es recomendable que lleve delante `call`, esto es debido a como Windows ejecuta varios comandos a través de archivos por lotes.
 * Para ejecutar un programa concreto, debemos escribir `call start "" "rutadelprograma"`.

 ---
