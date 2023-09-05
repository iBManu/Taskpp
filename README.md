# Taskpp

![taskpp](https://github.com/iBManu/Taskpp/assets/70716864/5112b005-8b71-49d0-b854-feea2685c8e8)

## EN | English

**Taskpp** is a command line program that automates the repetition of various commands through the creation of tasks.

The name of the program is a composition of the words task, app and cpp.

### Installation

You have two installation options. You can download the source code and compile it, or you can download the pre-compiled program. If you download the pre-compiled program, skip to step 5.

1. Download the cpp file.

2. Open a console in the folder where the file is located.

3. Execute the following command (You need to have MinGW installed, you can download it from the following link): https://sourceforge.net/projects/mingw/
```
g++ -o taskpp .\taskpp.cpp
or
gcc -o taskpp .\taskpp.cpp
```

4. Now you should have an taskpp.exe file.

5. On the D:/ drive, create a folder called 'Taskpp' and place the taskpp.exe executable in it.

6. Configure Taskpp in the Path environment variable:
  - Open 'Edit the system environment variables' in the Windows Control Panel.
  - Click on the 'environment Variables...' button.
  - There should be an environment variable named Path, click on it.
  - Click 'New' and add the D:\Taskpp directory.

7. You now have everything set up, and typing `taskpp` in any system console should launch the program.

### Use guide

**Taskpp** operates through the passing of commands and parameters. Using the command `taskpp help`, you will receive a list with brief information about each of them. Here's a guide with more detailed information:

* `taskpp add "name" ["description"]`: This command allows you to add a task with the specified name and description(optional). It then opens a text editor for you to add the desired commands. Example: `taskpp add task1 This is the number 1 task`

* `taskpp run "name"`: With this command, you execute the task with the specified name. Example: `taskpp run task1`

* `taskpp remove "name"`: You can use this command to delete the task with the specified name. Example: `taskpp remove task1`

* `taskpp edit "name"`: This command opens the task with the specified name in a text editor for modification. Example: `taskpp edit task1`

* `taskpp list`: This command displays a list of all available tasks.

* `taskpp help`: This command provides a list of the program's commands and their usage.

* `taskpp options`: This command allows you to change your program directory and default text editor.

* `taskpp version`: This command retrieves the version of **Taskpp** that you have installed.

* `taskpp info`: This command provides some information about **Taskpp**.

### Use example

I will create a task to automate working with React Native, which involves opening Visual Studio Code, Android Studio, and starting the Expo server. Here are the steps:

* Add a task by executing the command `taskpp add ReactNativeSetUp This task sets up the environment for working with React Native`.

* Next, in the text editor, add the following commands:

```
call code .
call start "" "C:\Program Files\Android\Android Studio\bin\studio64.exe"
call expo start
```

* Now, whenever you want to work on a React Native project, simply run `taskpp run ReactNativeSetUp` in your project folder, and everything will be done automatically.

### Recommendations

* It is advisable that each command within a task is preceded by `call`. This is due to how Windows executes various commands through batch files.
* To run a specific program, you should write `call start "" "programPath"`.

---

## ES | Español

**Taskpp** es un programa de linea de comandos que automatiza la repetición de varios comandos a través de la creación de tareas.

El nombre del programa es una composición de las palabras task, app y cpp.

### Instalación

Tienes dos opciones de instalación. Puedes descargar el codigo fuente y compilarlo o puedes descargar el programa ya compilado. Si descargas el programa ya compilado, salta hasta el punto 5.

1. Descarga el archivo cpp.
   
2. Abre una consola en la carpeta donde esté el archivo.
   
3. Ejecuta el siguiente comando (Necesitas tener instalado MinGW, puedes descargarlo en el siguiente enlace): https://sourceforge.net/projects/mingw/
```
g++ -o taskpp .\taskpp.cpp
o
gcc -o taskpp .\taskpp.cpp
```

4. Ahora deberías tener un archivo taskpp.exe.
  
5. En el disco D:/ crea una carpeta llama 'Taskpp', coloca ahí el ejecutable taskpp.exe.
  
6. Configura taskpp en la variable de entorno Path:
   - Abre `Editar variables de entorno` en el Panel de Control de Windows.
   - Clic en el botón `variables de entorno...`.
   - Debería aparecer una varible de entorno llamada Path, clic en ella.
   - Clic en `Nuevo` y añade la dirección D:\Taskpp.

7. Ya tienes todo configurado y escribiendo `taskpp` en cualquier consola del sistema debería iniciarse el programa.

 ### Guía de uso

Taskpp funciona a través del paso de comandos y parametros, con el comando ```taskpp help``` tendrás una lista con breve información de cada uno de ellos, aquí te dejo una guía con algo más de información:

* `taskpp add "nombre" ["descripción"]`: Con este comando añades una tarea con el nombre y descripción indicados, a continuación se abre un editor de texto para añadir los comandos que quieras. Ejemplo: `taskpp add tarea1 Esta es la tarea numero 1`

* `taskpp run "nombre"`: Con este comando ejecutas la tarea con el nombre indicado. Ejemplo: `taskpp run tarea1`

* `taskpp remove "nombre"`: Con este comando eliminas la tarea con el nombre indicado. Ejemplo: `taskpp remove tarea1`

* `taskpp edit "nombre"`: Con este comando se abre la tarea con el nombre indicado en el editor de texto para ser modificada. Ejemplo: `taskpp edit tarea1`

* `taskpp list`: Con este comando muestras una lista con todas las tareas disponibles.

* `taskpp help`: Con este comando obtienes una lista de los comandos del programa y su uso.

* `taskpp options`: Con este comando puedes cambiar el directorio del programa y el editor de texto predeterminado.

* `taskpp version`: Con este comando obtienes la versión de **Taskpp** que tienes instalada.

* `taskpp info`: Con este comando obtienes algo de información sobre **Taskpp**.

 ### Ejemplo de uso

Crearé una tarea para automatizar el trabajo con React Native, en este caso, quiero que abra el editor Visual Studio Code, Android Studio y que inicie el servidor de Expo, para ello haré lo siguiente.

* Agrego una tarea ejecutando el comando `taskpp add ReactNativeSetUp Esta tarea prepara el entorno para trabajar con React Native`

* A continuación, en el editor de texto añado los siguientes comandos.
```
call code .
call start "" "C:\Program Files\Android\Android Studio\bin\studio64.exe"
call expo start
```

* Ahora cada vez que quiera trabajar en algún proyecto con React Native, simplemente ejecuto `taskpp run ReactNativeSetUp` en la carpeta de mi proyecto y todo se hará automáticamente.

 ### Recomendaciones

 * Cada comando dentro de una tarea es recomendable que lleve delante `call`, esto es debido a como Windows ejecuta varios comandos a través de archivos por lotes.
 * Para ejecutar un programa concreto, debemos escribir `call start "" "rutadelprograma"`.

 ---
