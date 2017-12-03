# Archivo de idioma para español

Help_10="\n\t ${W}Script de compilación para Kodi Leia v${SCRIPT_VERSION}${END}"
Help_11="${YELLOW}--------------------------------------------------------------------${END} "
Help_12="${W}Uso:${END}"
Help_13="${1} \t\t- Esto es lo mismo que ${1} --with=clean,addons"
Help_14="${1} --help \t- Este mensaje muy útil"
Help_15="${1} --with= \t- Las opciones son: clean,dirty,addons,force,no-git,no-ccache,only-addons"
Help_16="\"clean\" eliminará el directorio kodi-build, lo recreará y compilará desde cero"
Help_17="\"dirty\" compilará como está"
Help_18="\"addons\" limpiará y (re) creará todos los complementos binarios"
Help_19="\"force\" compilará la fuente incluso si no hay actualizaciones de git"
Help_20="\"no-git\" saltará tirando de git y compilará e instalará"
Help_21="\"no-ccache\" desactivará ccache mientras configura Kodi"
Help_22="\"only-addons\" limpiará e instalará solo los complementos binarios"
Help_23="Puede usar cualquiera de estos en combinación, excepto ${W}clean${END} y ${W}dirty${END} juntos\n"
Help_24="${W}Ejemplos:${END}"
Help_25="Extrae de git, elimina el directorio de compilación, crea e instala localmente"
Help_26="\t${W}\$${END} ${1} --with=clean"
Help_27="Extrae de git y compila Leia (dirty)"
Help_28="\t${W}\$${END} ${1} --with=dirty"
Help_29="\n${YELLOW}Guionado por Stig-Ørjan Smelror <smelror@gmail.com>${END}"
Help_30="${YELLOW}Fuente se puede encontrar en https://github.com/kekePower/build.leia${END}"

L_10="Bienvenid(o/a) a"

L_20="Buscando actualizaciones para"
L_21="Actualización"
L_22="de git"
L_23="ya está actualizado".
L_24="La opción forzada está configurada".
L_25="Abortando!"

L_30="Iniciando el proceso de compilación"
L_31="Configurando"
L_33="Compilación"
L_34="Por favor espere ..."
L_35="Construir de"
L_36="falló. Inténtalo de nuevo".
L_37="(fresco)"
L_38="(limpio)"
L_39="(sucio)"

L_80="Eliminando"
L_81="(S/n)" # Sí o no
L_82="S" # Sí
L_83="s" # sí
    
L_90="Instalando Kodi a"
L_91="Limpiar complementos binarios"
L_92="Compilación e instalación de complementos binarios"
L_93="Ha elegido no instalar los complementos binarios en este momento".
L_94="Complementos que no pudieron compilar:"
L_95="(Solo)"
L_96="No se pudo encontrar a Kodi".
L_97="¿Desea eliminar ${PREFIX} antes de la instalación?"
L_98="Encontré una instalación anterior de Kodi en ${PREFIX}."
L_99="Progreso:"

L_100="Establecer los valores predeterminados para incluir"
L_101="No se puede hacer una compilación limpia y sucia al mismo tiempo".
L_102="Por favor, mira"
L_103="para más información".
L_104="Fuente de Kodi no encontrada. ¿Quieres que la busque?"
L_105="¿Desea compilar e instalar los complementos binarios?"
L_106="OK. No instalaré los complementos para usted".
L_107="Por favor, clona la fuente de Kodi en"
L_108="ya está actualizado. Nueva creación forzada".
L_109="ya está actualizado. No hay compilación nueva en este momento".
L_110="La construcción nocturna de"
L_111="error".
L_112="Clonación de la fuente Leia de Github".
L_113="Limpiar kodi-build"
L_114="Tener instalado el caché hará que la compilación sea más rápida"
L_115="si compilas Leia a menudo".
L_116="Limpiar el archivo ccache (ccache -C)"
L_117="¿Desea borrar el archivo de caché por completo?"
L_118="Limpiar la caché de caché aumentará significativamente los tiempos de compilación".
L_119="También se asegurará de que compile Kodi con las últimas bibliotecas".

L_120="Todo listo. Puedes ejecutar Kodi con el comando"
L_121="Puede ver el resultado del registro en este archivo"

L_130="no se encuentra git cound".
L_131="No se pudo encontrar RapidJSON".
L_132="libfmt no se pudo encontrar".
L_133="Por favor instala"

L_190="Gracias por usar"
L_191="para construir ${VERSION}"
L_192="Recuerde verificar https://github.com/kekePower/build.leia"
L_193="para actualizaciones y noticias".
L_197="Eliminando ${PREFIX}"