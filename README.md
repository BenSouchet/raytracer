# RT (Raytracer Engine & Renderer)

This raytracer is a program developed for my learning course at 42 school (Paris).<br />
The objective is to recreate from scratch a raytracer engine & renderer with a strong interface.<br />
<img align="center" src="http://i.imgur.com/nJ0HpUM.png" width="100%" />
<br />
Several options are available (see [Keyboard shortcuts](https://github.com/BenjaminSouchet/Filler_Visualizer#keyboard-shortcuts) section for more infos) :
* Play / Pause the progression of the battle
* Navigation between steps
* Change colors of the two AI
* Progression Bar
* Time elapsed

## Install & launch

### Install it

```bash
git clone https://github.com/BenjaminSouchet/RT.git ~/RT
cd ~/RT
make
```

### Start a scene

```
./rt scenes/{SCENE}.rt
```
{SCENE} : The scene you want to open (located in folder 'scenes')<br />
Example ⇣
```bash
./rt scenes/Solar_system.rt
```

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Play / Pause the battle</td>
<td valign="top" align="center"><kbd>&nbsp;return&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change colors of the AI</td>
<td valign="top" align="center"><kbd>&nbsp;shift&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">View the previous step of the battle</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">View the next step of the battle</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
</tbody>
</table>

## Contact or contribute

If you want to contact me, or fix / improve this project, just send me a mail at **bsouchet@student.42.fr**
