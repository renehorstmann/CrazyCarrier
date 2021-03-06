#include "u/pose.h"
#include "mathc/utils/camera.h"
#include "camera.h"


//
// sets up an orthogonal camera for pixel perfect rendering.
// coord system has a minimum square of [-90 : +90].
// render objects can use camera.gl for the transformation matrix.
//

// comment out to not use a pixel perfect camera
#define PIXEL_PERFECT


//
// public
//

Camera_s camera_new() {
    Camera_s self;
    self.matrices.v = mat4_eye();
    self.matrices.v_inv = mat4_eye();
    self.matrices.p = mat4_eye();
    self.matrices.p_inv = mat4_eye();
    self.matrices.vp = mat4_eye();
    self.matrices.v_p_inv = mat4_eye();
    return self;
}

void camera_update(Camera_s *self, int wnd_width, int wnd_height) {

    float smaller_size = wnd_width < wnd_height ? wnd_width : wnd_height;
    self->RO.real_pixel_per_pixel = smaller_size / CAMERA_SIZE;
    
#ifdef PIXEL_PERFECT
        self->RO.real_pixel_per_pixel = floorf(self->RO.real_pixel_per_pixel);
#endif

    float width_2 = wnd_width / (2 * self->RO.real_pixel_per_pixel);
    float height_2 = wnd_height / (2 * self->RO.real_pixel_per_pixel);

    // begin: (top, left) with a full pixel
    // end: (bottom, right) with a maybe splitted pixel
    self->RO.left = -floorf(width_2);
    self->RO.top = floorf(height_2);
    self->RO.right = width_2 + (width_2 - floorf(width_2));
    self->RO.bottom = -height_2 - (height_2 - floorf(height_2));

    self->matrices.p = mat4_camera_ortho(self->RO.left, self->RO.right, self->RO.bottom, self->RO.top, -1, 1);

    self->matrices.v_inv = mat4_inv(self->matrices.v);
    self->matrices.p_inv = mat4_inv(self->matrices.p);

    self->matrices.vp = mat4_mul_mat(self->matrices.p, self->matrices.v_inv);

    self->matrices.v_p_inv = mat4_mul_mat(self->matrices.v, self->matrices.p_inv);
}


void camera_set_pos(Camera_s *self, float x, float y) {
    u_pose_set_xy(&self->matrices.v, x, y);
}

void camera_set_size(Camera_s *self, float size) {
    u_pose_set_size(&self->matrices.v, size, size);
}

void camera_set_angle(Camera_s *self, float alpha) {
    u_pose_set_angle(&self->matrices.v, alpha);
}
