# libyuv-android
libyuv for android easy to  use

在根目录下的build.gradle 添加如下一行
-------------
Add it in your root build.gradle at the end of repositories:
-------------

	allprojects {
		repositories {
			...
			maven { url 'https://jitpack.io' }
		}
	}
	
然后，在你项目中的 build.gradle 添加如下一行
-------------
Step 2. Add the dependency
-------------

	dependencies {
	        compile 'com.github.garsonlab:libyuv-android:v1.1'
	}
API:
<ul>
    <li>ARGBToNV21();</li>
    <li>NV21ToARGB();</li>
    <li>RGBAToARGB();</li>
</ul>
