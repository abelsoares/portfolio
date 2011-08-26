<?php
/**
 * Proteus is an image resizer script.
 * @version 0.1
 * You can make an HTTP call and it will return a dinamic version of an image 
 * Supported image types: [png, jpg, gif]
 * @param string src - The path to the source image
 * @param string transform - the image transformation type [scale, resizeToHeight, resizeToWidth, resize, resizeBestFit, resizeExactFit]
 * 					  - scale: scale the image em percentage
 * 					  - resizeToHeight: resize an image to a certain height, the width is automatic calculated
 * 					  - resizeToWidth: resize an image to a certain width, the height is automatic calculated
 * 					  - resize: Resize an image to a given width and height, no constrain	 
 * 					  - resizeBestFit: Resize an image to low ratio, so it can fit into given dimensions, kepping constrains  
 * 					  - resizeExactFit: Resize an image to exact width and height, but keeping constrains.
 * @param string perc - to use with [type: scale], the scale to resize
 * @param string width - to use with [type: resize, resizeToWidth, resizeBestFit, resizeExactFit], width to use in transformation
 * @param string height - to use with [type: resize, resizeToHeiht, resizeBestFit, resizeExactFit], height to use in transformation
 * @param string bg_color - the image background color, to use with [type: resizeExactFit]
 *  
 */

//put this at the top of the page 
/*
   $mtime = microtime(); 
   $mtime = explode(" ",$mtime); 
   $mtime = $mtime[1] + $mtime[0]; 
   $starttime = $mtime; 
*/

/// GET ALL GET PARAMS
if(empty($_GET))
{
	echo "No params";
	exit(0);
}	

$proteus = new Proteus();

if(!empty($_GET['src']))
{
	if(!$proteus->load($_GET['src']))
	{	echo "File does not exist";
		exit(0);
	}
	if(!empty($_GET['transform']))
	{
		switch ($_GET['transform'])
		{
			case "scale":
				if(!empty($_GET['perc']) && is_numeric($_GET['perc']))
				{
					$proteus->scale($_GET['perc']);
				}
			break;
			
			case "resizeToHeight":
				if(!empty($_GET['height']) && is_numeric($_GET['height']))
				{
					$proteus->resizeToHeight($_GET['height']);
				}
			break;
						
			case "resizeToWidth":
				if(!empty($_GET['width']) && is_numeric($_GET['width']))
				{
					$proteus->resizeToHeight($_GET['width']);
				}
			break;
									
			case "resize":
				if( (!empty($_GET['width']) && is_numeric($_GET['width'])) &&  (!empty($_GET['height']) && is_numeric($_GET['height'])) )
				{
					$proteus->resize($_GET['width'], $_GET['height']);
				}
			break;
												
			case "resizeBestFit":
				if( (!empty($_GET['width']) && is_numeric($_GET['width'])) &&  (!empty($_GET['height']) && is_numeric($_GET['height'])) )
				{
					$proteus->resizeBestFit($_GET['width'], $_GET['height']);
				}
			break;
												
			case "resizeExactFit":
				if( (!empty($_GET['width']) && is_numeric($_GET['width'])) &&  (!empty($_GET['height']) && is_numeric($_GET['height'])) )
				{
					if(!empty($_GET['bg_color']))
					{
						list($proteus->bg_color['r'], $proteus->bg_color['g'], $proteus->bg_color['b']) = explode(",", $_GET['bg_color']);
						if(!validate_rgb_array($proteus->bg_color))
							$proteus->bg_color = array();
					}
					$proteus->resizeExactFit($_GET['width'], $_GET['height']);
				}
			break;
		}
				
	}
}

/**
 * 
 * Validate as color rgb array
 * @param array $color_array, expected as array('r'=>[0-255 value], 'g'=>[0-255 value], 'b'=>[0-255 value])
 * @return TRUE on sucess, FALSE on failure
 */
function validate_rgb_array($color_array)
{
	if(empty($color_array['r']) || empty($color_array['g']) || empty($color_array['b']))
		return FALSE;
	if(!is_numeric($color_array['r']) || !is_numeric($color_array['g']) || !is_numeric($color_array['b']))
		return FALSE;
	if( (0 > $color_array['r']) || (0 > $color_array['g']) || (0 > $color_array['b']) ||
		 (255 < $color_array['r']) || (255 < $color_array['g']) || (255 < $color_array['b']) )					
		return FALSE;
	
	return TRUE;
}

$proteus->output();

// put this code at the bottom of the page 
/*
   $mtime = microtime(); 
   $mtime = explode(" ",$mtime); 
   $mtime = $mtime[1] + $mtime[0]; 
   $endtime = $mtime; 
   $totaltime = ($endtime - $starttime); 
   echo "This page was created in ".$totaltime." seconds"; 
*/
/**
 * Return file extension
 * @param string $filename
 * @return string file extension
 */
function file_extension($filename)
{
    $path_info = pathinfo($filename);
    return $path_info['extension'];
}

class Proteus{
   
   var $image;
   
   var $image_type;
   
   var $srcDir;
   
   var $destDir;
   
   var $imgName;
 
   var $mime;
   
   var $quality = 9;
   
   var $bg_color = array();
   
   /**
    * 
    * Tries to load an image into GD
    * @param string $filename - path to the file
    * @return TRUE on sucess, FALSE on failure
    */
   function load($filename) {
   	  if(!file_exists($filename))	
   	  	return FALSE;
   	  $this->imgName = $filename;
   	  if($this->srcDir)
   	  	$filename = WWW_ROOT . $this->srcDir . $filename;
      $image_info = getimagesize($filename);
      if(!$image_info) return FALSE;
      
      $this->mime = $image_info['mime'];
      $this->image_type = $image_info[2];      
      if( $this->image_type == IMAGETYPE_JPEG ) {
         $this->image = imagecreatefromjpeg($filename);
      } elseif( $this->image_type == IMAGETYPE_GIF ) {
      	$this->image = imagecreatefromgif($filename);
      } elseif( $this->image_type == IMAGETYPE_PNG ) {

         $this->image = imagecreatefrompng($filename);
      }
      return TRUE;
   }
   function isImage()
   {
   	if($this->image)
   		return true;
   	else 
   		return false;
   }
   function saveAlt($filename)
   {
   	$filename = $filename.$this->imgName;
   	$this->save($filename);
   }
   
   function save($filename = null, $image_type=IMAGETYPE_JPEG, $compression=75, $permissions=null) {
   	  if(!$filename)
   	  	$filename = $this->imgName;
   	  if(!$this->destDir)
   	  	$this->destDir = $this->srcDir;
   	  $filename = WWW_ROOT . $this->destDir . $filename;
   	  
      if( $image_type == IMAGETYPE_JPEG ) {
         imagejpeg($this->image,$filename,$compression);
      } elseif( $image_type == IMAGETYPE_GIF ) {
         imagegif($this->image,$filename);         
      } elseif( $image_type == IMAGETYPE_PNG ) {
         imagepng($this->image,$filename);
      }   
      if( $permissions != null) {
         chmod($filename,$permissions);
      }
   }
   
   function output() {
   	  //Set the background color
	  header("Content-type: ".$this->mime);
      if( $this->image_type == IMAGETYPE_JPEG ) {
         imagejpeg($this->image, NULL,$this->quality);
      } elseif( $this->image_type == IMAGETYPE_GIF ) {
         imagegif($this->image, NULL,$this->quality);         
      } elseif( $this->image_type == IMAGETYPE_PNG ) {
         imagepng($this->image, NULL,$this->quality);
      }   
   }
   
   function getWidth() {
      return imagesx($this->image);
   }
   
   function getHeight() {
      return imagesy($this->image);
   }
   
   function resizeToHeight($height) {
      $ratio = $height / $this->getHeight();
      $width = $this->getWidth() * $ratio;
      $this->resize($width,$height);
   }
   
   function resizeToWidth($width) {
      $ratio = $width / $this->getWidth();
      $height = $this->getheight() * $ratio;
      $this->resize($width,$height);
   }
   
   function scale($scale) {
      $width = $this->getWidth() * $scale/100;
      $height = $this->getheight() * $scale/100; 
      $this->resize($width,$height);
   }
   
   function resize($width,$height) {
      $new_image = imagecreatetruecolor($width, $height);
      imagecopyresampled($new_image, $this->image, 0, 0, 0, 0, $width, $height, $this->getWidth(), $this->getHeight());
      $this->image = $new_image;   
   } 
      
   function resizeBestFit($width,$height) {
   		/// resize to the lowest ratio, so image can fit into given dimensions
   		if( ($width/$this->getWidth()) < ($height/$this->getHeight()) )
   			$this->resizeToWidth($width);
   		else
 			$this->resizeToHeight($height);
   		  		
//      $new_image = imagecreatetruecolor($width, $height);
//      imagecopyresampled($new_image, $this->image, 0, 0, 0, 0, $width, $height, $this->getWidth(), $this->getHeight());
//      $this->image = $new_image;   
   }
   function resizeExactFit($width,$height) {
   		/// resize to the lowest ratio, so image can fit into given dimensions
   		$this->resizeBestFit($width, $height);  		
	    $new_image = imagecreatetruecolor($width, $height);
	    if(!empty($this->bg_color))
		{
	        $bg = imagecolorallocate($new_image, $this->bg_color['r'], $this->bg_color['g'], $this->bg_color['b']);
    	    imagefill($new_image, 0, 0, $bg);
		}
        $posX = $posY = 0;
        if($width > $this->getWidth())
        {
        	$posX = ($width - $this->getWidth())/2;
        }
        if($height > $this->getHeight())
        {
        	$posY = ($height - $this->getHeight())/2;
        }
        
        imagecopy($new_image, $this->image, $posX, $posY, 0, 0, $this->getWidth(), $this->getHeight());
        $this->image = $new_image;   
   }  
	
	/**
	 * 
	 * Return true if file extension is a valid one
	 * @param unknown_type $extension
	 */
	function is_extension_valid($extension)
	{
		
	}
	/**
	 * 
	 *   
	 * Plug-and-Play fastimagecopyresampled function replaces much slower imagecopyresampled.
	   Just include this function and change all "imagecopyresampled" references to "fastimagecopyresampled".
	   Typically from 30 to 60 times faster when reducing high resolution images down to thumbnail size using the default quality setting.
	   Author: Tim Eckel - Date: 09/07/07 - Version: 1.1 - Project: FreeRingers.net - Freely distributable - These comments must remain.
	  
	   Optional "quality" parameter (defaults is 3). Fractional values are allowed, for example 1.5. Must be greater than zero.
	   Between 0 and 1 = Fast, but mosaic results, closer to 0 increases the mosaic effect.
	   1 = Up to 350 times faster. Poor results, looks very similar to imagecopyresized.
	   2 = Up to 95 times faster.  Images appear a little sharp, some prefer this over a quality of 3.
	   3 = Up to 60 times faster.  Will give high quality smooth results very close to imagecopyresampled, just faster.
	   4 = Up to 25 times faster.  Almost identical to imagecopyresampled for most images.
	   5 = No speedup. Just uses imagecopyresampled, no advantage over imagecopyresampled.
	
	 * @param unknown_type $dst_image
	 * @param unknown_type $src_image
	 * @param unknown_type $dst_x
	 * @param unknown_type $dst_y
	 * @param unknown_type $src_x
	 * @param unknown_type $src_y
	 * @param unknown_type $dst_w
	 * @param unknown_type $dst_h
	 * @param unknown_type $src_w
	 * @param unknown_type $src_h
	 * @param unknown_type $quality
	 */
	function fastimagecopyresampled (&$dst_image, $src_image, $dst_x, $dst_y, $src_x, $src_y, $dst_w, $dst_h, $src_w, $src_h, $quality = 3) {
	  if (empty($src_image) || empty($dst_image) || $quality <= 0) { return false; }
	  if ($quality < 5 && (($dst_w * $quality) < $src_w || ($dst_h * $quality) < $src_h)) {
	    $temp = imagecreatetruecolor ($dst_w * $quality + 1, $dst_h * $quality + 1);
	    imagecopyresized ($temp, $src_image, 0, 0, $src_x, $src_y, $dst_w * $quality + 1, $dst_h * $quality + 1, $src_w, $src_h);
	    imagecopyresampled ($dst_image, $temp, $dst_x, $dst_y, 0, 0, $dst_w, $dst_h, $dst_w * $quality, $dst_h * $quality);
	    imagedestroy ($temp);
	  } else imagecopyresampled ($dst_image, $src_image, $dst_x, $dst_y, $src_x, $src_y, $dst_w, $dst_h, $src_w, $src_h);
	  return true;
	}
}
?>
