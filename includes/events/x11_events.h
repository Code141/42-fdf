/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:59:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/10 20:29:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11_EVENTS_H
# define X11_EVENTS_H

# define KeyPress				2
# define KeyRelease				3
# define MotionNotify			6
# define ButtonRelease			5

# define KeyPressMask			(1L<<0)
# define KeyReleaseMask			(1L<<1)
# define PointerMotionMask		(1L<<6)
# define ButtonReleaseMask		(1L<<3)





# define ButtonPressMask			(1L<<2)
# define EnterWindowMask			(1L<<4)
# define LeaveWindowMask			(1L<<5)

# define PointerMotionHintMask		(1L<<7)

# define ButtonMotionMask			(1L<<13)
# define KeymapStateMask			(1L<<14)
# define ExposureMask				(1L<<15)
# define VisibilityChangeMask		(1L<<16)
# define StructureNotifyMask		(1L<<17)
# define ResizeRedirectMask			(1L<<18)
# define FocusChangeMask			(1L<<21)
# define PropertyChangeMask			(1L<<22)
# define ColormapChangeMask			(1L<<23)
# define OwnerGrabButtonMask		(1L<<24)

# define ButtonPress		4
# define EnterNotify		7
# define LeaveNotify		8
# define FocusIn			9
# define FocusOut			10

# define KeymapNotify		11
# define Expose				12
# define GraphicsExpose		13
# define NoExpose			14
# define VisibilityNotify	15
# define CreateNotify		16
# define DestroyNotify		17
# define UnmapNotify		18
# define MapNotify			19
# define MapRequest			20
# define ReparentNotify		21
# define ConfigureNotify	22
# define ConfigureRequest	23
# define GravityNotify		24
# define ResizeRequest		25
# define CirculateNotify	26
# define CirculateRequest	27
# define PropertyNotify		28
# define SelectionClear		29
# define SelectionRequest	30
# define SelectionNotify	31
# define ColormapNotify		32
# define ClientMessage		33
# define MappingNotify		34
# define LASTEvent			35

#endif
