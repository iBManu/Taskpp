# Autotask
## EN | English

**Autotask** is a command line program that automates the repetition of various commands through the creation of tasks.
### Installation

You have several installation options. You can choose to download the source code and compile it, or you can download the pre-compiled program. If you download the pre-compiled program, skip to step 5.

* Download the cpp file.

* Open a console in the folder where the file is located.

* Execute the following command (You need to have MinGW installed, you can download it from the following link): https://sourceforge.net/projects/mingw/
```
g++ -o autotask .\autojob.cpp
or
gcc -o autotask .\autojob.cpp
```

* Now you should have an autojob.exe file.

* On the D:/ drive, create a folder called 'Autotask' and place the autotask.exe executable in it.

* Configure Autotask in the Path environment variable:
  - Open 'Edit the system environment variables' in the Windows Control Panel.
  - Click on the 'Environment Variables...' button.
  - There should be an environment variable named Path, click on it.
  - Click 'New' and add the D:\Autotask directory.
  - 
* You now have everything set up, and typing `autotask` in any system console should launch the program.

---

## ES | Español

**Autotask** es un programa de linea de comandos que automatiza la repetición de varios comandos a través de la creación de tareas.

### Instalación

Tienes varias opciones de instalación. Puedes decidir descargar el codigo fuente y compilarlo o puedes descargar el programa ya compilado. Si descargas el programa ya compilado, salta hasta el punto 5.

1. Descarga el archivo cpp.
   
3. Abre una consola en la carpeta donde esté el archivo.
   
5. Ejecuta el siguiente comando (Necesitas tener instalado MinGW, puedes descargarlo en el siguiente enlace): https://sourceforge.net/projects/mingw/
```
g++ -o autotask .\autojob.cpp
o
gcc -o autotask .\autojob.cpp
```

4. Ahora deberías tener un archivo autojob.exe.
  
6. En el disco D:/ crea una carpeta llama 'Autotask', coloca ahí el ejecutable autotask.exe.
  
8. Configura autotask en la variable de entorno Path:
   - Abre `Editar variables de entorno` en el Panel de Control de Windows.
   - Clic en el botón `variables de entorno...`.
   - Debería aparecer una varible de entorno llamada Path, clic en ella.
   - Clic en `Nuevo` y añade la dirección D:\Autotask.

9. Ya tienes todo configurado y escribiendo `autotask` en cualquier consola del sistema debería iniciarse el programa.

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

* Crearé una tarea para automatizar el trabajo con React Native, en este caso, quiero que abra el editor Visual Studio Code, Android Studio y que inicie el servidor expo, para ello haré lo siguiente.

* Ejecuto el comando `autotask run ReactNativeSetUp Esta tarea prepara el entorno para trabajar con React Native`

* A continuación, en el editor de texto añado los siguientes comandos.
```
call code .
call start "" "C:\Program Files\Android\Android Studio\bin\studio64.exe"
call expo start
```

* Ahora cada vez que quiera trabajar en algún proyecto con React Native, simplemente ejecuto ```autotask run ReactNativeSetUp``` en la carpeta de mi proyecto y todo se hará automáticamente.

 ### Recomendaciones

 * Cada comando dentro de una tarea es recomendable que lleve delante `call`, esto es debido a como Windows ejecuta varios comandos a través de archivos por lotes.
 * Para ejecutar un programa concreto, debemos escribir `call start "" "rutadelprograma"`.

 ---
