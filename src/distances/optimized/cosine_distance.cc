/**
 * © Copyright IBM Corporation 2024. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(__powerpc__)

#include <iostream>
#include "cosine_distance.h"

#include <cmath>

namespace powerpc {

// float
// cosine_distance_ref_ppc (const float* x, const float* y, size_t d)
// {
//     float res = 0.0, dotpdt = 0.0, mag_vx = 0.0, mag_vy=0.0;
//     size_t base;
//     vector float *vx, *vy;
//     vector float vdotpdt = {0.0, 0.0, 0.0, 0.0};
//     vector float sqr_mag_vx = {0.0, 0.0, 0.0, 0.0};
//     vector float sqr_mag_vy = {0.0, 0.0, 0.0, 0.0};
//     vector float vres = {0.0, 0.0, 0.0, 0.0};

//     base = (d / FLOAT_VEC_SIZE) * FLOAT_VEC_SIZE;

//     for (size_t i = 0; i < base; i = i + FLOAT_VEC_SIZE) 
//         {
//             vx = (vector float *) (&x[i]);
//             vy = (vector float *) (&y[i]);

//             vdotpdt += vx[0] * vy[0];
//             sqr_mag_vx += vx[0] * vx[0];
//             sqr_mag_vy += vy[0] * vy[0];
//         }            

//     dotpdt = vdotpdt[0] + vdotpdt[1] + vdotpdt[2] + vdotpdt[3];

//     mag_vx = sqr_mag_vx[0] + sqr_mag_vx[1] + sqr_mag_vx[2] + sqr_mag_vx[3];
//     mag_vy = sqr_mag_vy[0] + sqr_mag_vy[1] + sqr_mag_vy[2] + sqr_mag_vy[3];

//     /* Handle any remaining data elements */
//     for (size_t i = base; i < d; i++)
//     {
//         dotpdt += x[i] * y[i];
//         mag_vx += x[i] * x[i];
//         mag_vy += y[i] * y[i];
        
//     }
//     res = 1.0f - (dotpdt/(sqrt(mag_vx * mag_vy)));
//     return res;
// }

float
cosine_distance_ref_ppc (const float* x, const float* y, size_t d)
{
    float res = 0.0, dotpdt = 0.0, mag_vx = 0.0, mag_vy = 0.0;
    size_t base, factor;
    vector float *vx, *vy;
    vector float vdotpdt = {0.0, 0.0, 0.0, 0.0};
    vector float sqr_mag_vx = {0.0, 0.0, 0.0, 0.0};
    vector float sqr_mag_vy = {0.0, 0.0, 0.0, 0.0};

    if(d >= 128){
        factor = FLOAT_VEC_SIZE * 16;
        base = (d / factor) * factor;
        for(size_t i = 0; i < base; i = i + factor)
        {
            vx = (vector float *) (&x[i + 0*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 0*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 1*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 1*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 2*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 2*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 3*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 3*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 4*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 4*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 5*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 5*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 6*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 6*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 7*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 7*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 8*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 8*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 9*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 9*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 10*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 10*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 11*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 11*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 12*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 12*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 13*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 13*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 14*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 14*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 15*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 15*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];
        }
    }
    else{
        factor = FLOAT_VEC_SIZE*4;
        base = (d / factor) * factor;
        for(size_t i = 0; i < base; i = i + factor)
        {
            vx = (vector float *) (&x[i + 0*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 0*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 1*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 1*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 2*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 2*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];

            vx = (vector float *) (&x[i + 3*FLOAT_VEC_SIZE]);
            vy = (vector float *) (&y[i + 3*FLOAT_VEC_SIZE]);

            vdotpdt += vx[0] * vy[0];
            sqr_mag_vx += vx[0] * vx[0];
            sqr_mag_vy += vy[0] * vy[0];
        }
    }

    dotpdt = vdotpdt[0] + vdotpdt[1] + vdotpdt[2] + vdotpdt[3];
    mag_vx  = sqr_mag_vx[0] + sqr_mag_vx[1] + sqr_mag_vx[2] + sqr_mag_vx[3];
    mag_vy  = sqr_mag_vy[0] + sqr_mag_vy[1] + sqr_mag_vy[2] + sqr_mag_vy[3];

    // Handle remaining elements
    for (size_t i = base; i < d; ++i)
    {
        dotpdt += x[i] * y[i];
        mag_vx += x[i] * x[i];
        mag_vy += y[i] * y[i];
    }

    res = 1.0f - (dotpdt / (sqrt(mag_vx * mag_vy)));
    return res;
}

} // namespace powerpc

#endif
