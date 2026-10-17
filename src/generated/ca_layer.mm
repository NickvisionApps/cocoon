#include "generated/ca_layer.h"
#include "internal.h"

@interface AKCALayerDelegate : NSObject <CALayerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKCALayerDelegate

- (void)displayLayer:(CALayer*)layer
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CALayer, void()>::emit((__bridge void*)strongHost, "display_layer");
}

- (void)drawLayer:(CALayer*)layer inContext:(CGContextRef)ctx
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CALayer, void(cocoon::CGContext)>::emit((__bridge void*)strongHost, "draw_layer_in_context", cocoon::internal::wrap_cf<cocoon::CGContext>((const void*)(ctx)));
}

- (void)layerWillDraw:(CALayer*)layer
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CALayer, void()>::emit((__bridge void*)strongHost, "layer_will_draw");
}

- (void)layoutSublayersOfLayer:(CALayer*)layer
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CALayer, void()>::emit((__bridge void*)strongHost, "layout_sublayers_of_layer");
}

- (id<CAAction>)actionForLayer:(CALayer*)layer forKey:(NSString*)event
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::CALayer, cocoon::Object(std::string)>::emit((__bridge void*)strongHost, "action_for_layer_for_key", cocoon::internal::from(event));
    return cocoon::internal::native_id(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(displayLayer:))
    {
        return strongHost && cocoon::Signal<cocoon::CALayer, void()>::connected((__bridge void*)strongHost, "display_layer");
    }
    if (selector == @selector(drawLayer:inContext:))
    {
        return strongHost && cocoon::Signal<cocoon::CALayer, void(cocoon::CGContext)>::connected((__bridge void*)strongHost, "draw_layer_in_context");
    }
    if (selector == @selector(layerWillDraw:))
    {
        return strongHost && cocoon::Signal<cocoon::CALayer, void()>::connected((__bridge void*)strongHost, "layer_will_draw");
    }
    if (selector == @selector(layoutSublayersOfLayer:))
    {
        return strongHost && cocoon::Signal<cocoon::CALayer, void()>::connected((__bridge void*)strongHost, "layout_sublayers_of_layer");
    }
    if (selector == @selector(actionForLayer:forKey:))
    {
        return strongHost && cocoon::Signal<cocoon::CALayer, cocoon::Object(std::string)>::connected((__bridge void*)strongHost, "action_for_layer_for_key");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    CALayer::CALayer(const Object& layer) : CALayer(Adopt{cocoon::internal::retain([[::CALayer alloc] initWithLayer:cocoon::internal::native_id(layer)])})
    {
        CALayer::install_delegate_delegate_(handle());
    }

    CALayer::CALayer() : CALayer(Adopt{cocoon::internal::retain([[::CALayer alloc] init])})
    {
        CALayer::install_delegate_delegate_(handle());
    }

    CALayer::CALayer(std::nullptr_t) : Object(nullptr)
    {
    }

    CALayer::CALayer(Adopt adopt) : Object(adopt)
    {
    }

    Object CALayer::action_for_key(const std::string& event) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CALayer>(this) actionForKey:cocoon::internal::to(event)]);
    }

    void CALayer::add_animation(const Object& anim, const std::string& key) const
    {
        [cocoon::internal::ns<::CALayer>(this) addAnimation:cocoon::internal::native_id(anim) forKey:cocoon::internal::to(key)];
    }

    void CALayer::add_sublayer(const CALayer& layer) const
    {
        [cocoon::internal::ns<::CALayer>(this) addSublayer:cocoon::internal::native<::CALayer>(layer)];
    }

    AffineTransform3 CALayer::affine_transform() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) affineTransform]);
    }

    Object CALayer::animation_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CALayer>(this) animationForKey:cocoon::internal::to(key)]);
    }

    std::vector<std::string> CALayer::animation_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::CALayer>(this) animationKeys], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool CALayer::contains_point(const Point& p) const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) containsPoint:cocoon::internal::to(p)]);
    }

    bool CALayer::contents_are_flipped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) contentsAreFlipped]);
    }

    Point CALayer::convert_point(const Point& p, const CALayer& l) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) convertPoint:cocoon::internal::to(p) fromLayer:cocoon::internal::native<::CALayer>(l)]);
    }

    Rect CALayer::convert_rect(const Rect& r, const CALayer& l) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) convertRect:cocoon::internal::to(r) fromLayer:cocoon::internal::native<::CALayer>(l)]);
    }

    double CALayer::convert_time(double t, const CALayer& l) const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) convertTime:static_cast<::CFTimeInterval>(t) fromLayer:cocoon::internal::native<::CALayer>(l)]);
    }

    double CALayer::corner_curve_expansion_factor(const std::string& curve)
    {
        return static_cast<double>([::CALayer cornerCurveExpansionFactor:cocoon::internal::to(curve)]);
    }

    Object CALayer::default_action_for_key(const std::string& event)
    {
        return cocoon::internal::wrap<Object>([::CALayer defaultActionForKey:cocoon::internal::to(event)]);
    }

    Object CALayer::default_value_for_key(const std::string& key)
    {
        return cocoon::internal::wrap<Object>([::CALayer defaultValueForKey:cocoon::internal::to(key)]);
    }

    void CALayer::display() const
    {
        [cocoon::internal::ns<::CALayer>(this) display];
    }

    void CALayer::display_if_needed() const
    {
        [cocoon::internal::ns<::CALayer>(this) displayIfNeeded];
    }

    void CALayer::draw_in_context(const CGContext& ctx) const
    {
        [cocoon::internal::ns<::CALayer>(this) drawInContext:((::CGContextRef)(ctx).handle())];
    }

    CALayer CALayer::hit_test(const Point& p) const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::CALayer>(this) hitTest:cocoon::internal::to(p)]);
    }

    void CALayer::insert_sublayer(const CALayer& layer, const CALayer& sibling) const
    {
        [cocoon::internal::ns<::CALayer>(this) insertSublayer:cocoon::internal::native<::CALayer>(layer) above:cocoon::internal::native<::CALayer>(sibling)];
    }

    void CALayer::insert_sublayer(const CALayer& layer, unsigned int idx) const
    {
        [cocoon::internal::ns<::CALayer>(this) insertSublayer:cocoon::internal::native<::CALayer>(layer) atIndex:static_cast<unsigned int>(idx)];
    }

    CALayer CALayer::layer()
    {
        return cocoon::internal::wrap<CALayer>([::CALayer layer]);
    }

    void CALayer::layout_if_needed() const
    {
        [cocoon::internal::ns<::CALayer>(this) layoutIfNeeded];
    }

    void CALayer::layout_sublayers() const
    {
        [cocoon::internal::ns<::CALayer>(this) layoutSublayers];
    }

    CALayer CALayer::model_layer() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::CALayer>(this) modelLayer]);
    }

    bool CALayer::needs_display() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) needsDisplay]);
    }

    bool CALayer::needs_display_for_key(const std::string& key)
    {
        return static_cast<bool>([::CALayer needsDisplayForKey:cocoon::internal::to(key)]);
    }

    bool CALayer::needs_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) needsLayout]);
    }

    Size CALayer::preferred_frame_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) preferredFrameSize]);
    }

    CALayer CALayer::presentation_layer() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::CALayer>(this) presentationLayer]);
    }

    void CALayer::remove_all_animations() const
    {
        [cocoon::internal::ns<::CALayer>(this) removeAllAnimations];
    }

    void CALayer::remove_animation_for_key(const std::string& key) const
    {
        [cocoon::internal::ns<::CALayer>(this) removeAnimationForKey:cocoon::internal::to(key)];
    }

    void CALayer::remove_from_superlayer() const
    {
        [cocoon::internal::ns<::CALayer>(this) removeFromSuperlayer];
    }

    void CALayer::render_in_context(const CGContext& ctx) const
    {
        [cocoon::internal::ns<::CALayer>(this) renderInContext:((::CGContextRef)(ctx).handle())];
    }

    void CALayer::replace_sublayer(const CALayer& old_layer, const CALayer& new_layer) const
    {
        [cocoon::internal::ns<::CALayer>(this) replaceSublayer:cocoon::internal::native<::CALayer>(old_layer) with:cocoon::internal::native<::CALayer>(new_layer)];
    }

    void CALayer::resize_sublayers_with_old_size(const Size& size) const
    {
        [cocoon::internal::ns<::CALayer>(this) resizeSublayersWithOldSize:cocoon::internal::to(size)];
    }

    void CALayer::resize_with_old_superlayer_size(const Size& size) const
    {
        [cocoon::internal::ns<::CALayer>(this) resizeWithOldSuperlayerSize:cocoon::internal::to(size)];
    }

    void CALayer::set_affine_transform(const AffineTransform3& m) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAffineTransform:cocoon::internal::to(m)];
    }

    void CALayer::set_needs_display() const
    {
        [cocoon::internal::ns<::CALayer>(this) setNeedsDisplay];
    }

    void CALayer::set_needs_display_in_rect(const Rect& r) const
    {
        [cocoon::internal::ns<::CALayer>(this) setNeedsDisplayInRect:cocoon::internal::to(r)];
    }

    void CALayer::set_needs_layout() const
    {
        [cocoon::internal::ns<::CALayer>(this) setNeedsLayout];
    }

    bool CALayer::should_archive_value_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) shouldArchiveValueForKey:cocoon::internal::to(key)]);
    }

    std::map<std::string, Object> CALayer::actions() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::CALayer>(this) actions], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void CALayer::set_actions(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setActions:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                          {
                                                                                              return cocoon::internal::to(k);
                                                                                          },
                                                                                          [](const Object& v) -> id
                                                                                          {
                                                                                              return cocoon::internal::native_id(v);
                                                                                          })];
    }

    bool CALayer::allows_edge_antialiasing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) allowsEdgeAntialiasing]);
    }

    void CALayer::set_allows_edge_antialiasing(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAllowsEdgeAntialiasing:static_cast<::BOOL>(value)];
    }

    bool CALayer::allows_group_opacity() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) allowsGroupOpacity]);
    }

    void CALayer::set_allows_group_opacity(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAllowsGroupOpacity:static_cast<::BOOL>(value)];
    }

    Point CALayer::anchor_point() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) anchorPoint]);
    }

    void CALayer::set_anchor_point(const Point& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAnchorPoint:cocoon::internal::to(value)];
    }

    double CALayer::anchor_point_z() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) anchorPointZ]);
    }

    void CALayer::set_anchor_point_z(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAnchorPointZ:static_cast<::CGFloat>(value)];
    }

    CAAutoresizingMask CALayer::autoresizing_mask() const
    {
        return static_cast<CAAutoresizingMask>([cocoon::internal::ns<::CALayer>(this) autoresizingMask]);
    }

    void CALayer::set_autoresizing_mask(CAAutoresizingMask value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setAutoresizingMask:static_cast<::CAAutoresizingMask>(value)];
    }

    CGColor CALayer::background_color() const
    {
        return cocoon::internal::wrap_cf<CGColor>((const void*)([cocoon::internal::ns<::CALayer>(this) backgroundColor]));
    }

    void CALayer::set_background_color(const CGColor& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setBackgroundColor:((::CGColorRef)(value).handle())];
    }

    std::vector<Object> CALayer::background_filters() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::CALayer>(this) backgroundFilters], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void CALayer::set_background_filters(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setBackgroundFilters:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native_id(e);
                                                                                               })];
    }

    CGColor CALayer::border_color() const
    {
        return cocoon::internal::wrap_cf<CGColor>((const void*)([cocoon::internal::ns<::CALayer>(this) borderColor]));
    }

    void CALayer::set_border_color(const CGColor& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setBorderColor:((::CGColorRef)(value).handle())];
    }

    double CALayer::border_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) borderWidth]);
    }

    void CALayer::set_border_width(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setBorderWidth:static_cast<::CGFloat>(value)];
    }

    Rect CALayer::bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) bounds]);
    }

    void CALayer::set_bounds(const Rect& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setBounds:cocoon::internal::to(value)];
    }

    Object CALayer::compositing_filter() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CALayer>(this) compositingFilter]);
    }

    void CALayer::set_compositing_filter(const Object& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setCompositingFilter:cocoon::internal::native_id(value)];
    }

    Object CALayer::contents() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CALayer>(this) contents]);
    }

    void CALayer::set_contents(const Object& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContents:cocoon::internal::native_id(value)];
    }

    Rect CALayer::contents_center() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) contentsCenter]);
    }

    void CALayer::set_contents_center(const Rect& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsCenter:cocoon::internal::to(value)];
    }

    std::string CALayer::contents_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) contentsFormat]);
    }

    void CALayer::set_contents_format(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsFormat:cocoon::internal::to(value)];
    }

    std::string CALayer::contents_gravity() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) contentsGravity]);
    }

    void CALayer::set_contents_gravity(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsGravity:cocoon::internal::to(value)];
    }

    double CALayer::contents_headroom() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) contentsHeadroom]);
    }

    void CALayer::set_contents_headroom(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsHeadroom:static_cast<::CGFloat>(value)];
    }

    Rect CALayer::contents_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) contentsRect]);
    }

    void CALayer::set_contents_rect(const Rect& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsRect:cocoon::internal::to(value)];
    }

    double CALayer::contents_scale() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) contentsScale]);
    }

    void CALayer::set_contents_scale(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setContentsScale:static_cast<::CGFloat>(value)];
    }

    std::string CALayer::corner_curve() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) cornerCurve]);
    }

    void CALayer::set_corner_curve(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setCornerCurve:cocoon::internal::to(value)];
    }

    double CALayer::corner_radius() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) cornerRadius]);
    }

    void CALayer::set_corner_radius(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setCornerRadius:static_cast<::CGFloat>(value)];
    }

    bool CALayer::is_double_sided() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) isDoubleSided]);
    }

    void CALayer::set_double_sided(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setDoubleSided:static_cast<::BOOL>(value)];
    }

    bool CALayer::draws_asynchronously() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) drawsAsynchronously]);
    }

    void CALayer::set_draws_asynchronously(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setDrawsAsynchronously:static_cast<::BOOL>(value)];
    }

    CAEdgeAntialiasingMask CALayer::edge_antialiasing_mask() const
    {
        return static_cast<CAEdgeAntialiasingMask>([cocoon::internal::ns<::CALayer>(this) edgeAntialiasingMask]);
    }

    void CALayer::set_edge_antialiasing_mask(CAEdgeAntialiasingMask value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setEdgeAntialiasingMask:static_cast<::CAEdgeAntialiasingMask>(value)];
    }

    std::vector<Object> CALayer::filters() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::CALayer>(this) filters], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void CALayer::set_filters(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setFilters:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(e);
                                                                                     })];
    }

    Rect CALayer::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) frame]);
    }

    void CALayer::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setFrame:cocoon::internal::to(value)];
    }

    bool CALayer::is_geometry_flipped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) isGeometryFlipped]);
    }

    void CALayer::set_geometry_flipped(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setGeometryFlipped:static_cast<::BOOL>(value)];
    }

    bool CALayer::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) isHidden]);
    }

    void CALayer::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setHidden:static_cast<::BOOL>(value)];
    }

    Object CALayer::layout_manager() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CALayer>(this) layoutManager]);
    }

    void CALayer::set_layout_manager(const Object& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setLayoutManager:cocoon::internal::native_id(value)];
    }

    std::string CALayer::magnification_filter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) magnificationFilter]);
    }

    void CALayer::set_magnification_filter(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMagnificationFilter:cocoon::internal::to(value)];
    }

    CALayer CALayer::mask() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::CALayer>(this) mask]);
    }

    void CALayer::set_mask(const CALayer& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMask:cocoon::internal::native<::CALayer>(value)];
    }

    CACornerMask CALayer::masked_corners() const
    {
        return static_cast<CACornerMask>([cocoon::internal::ns<::CALayer>(this) maskedCorners]);
    }

    void CALayer::set_masked_corners(CACornerMask value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMaskedCorners:static_cast<::CACornerMask>(value)];
    }

    bool CALayer::masks_to_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) masksToBounds]);
    }

    void CALayer::set_masks_to_bounds(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMasksToBounds:static_cast<::BOOL>(value)];
    }

    std::string CALayer::minification_filter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) minificationFilter]);
    }

    void CALayer::set_minification_filter(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMinificationFilter:cocoon::internal::to(value)];
    }

    float CALayer::minification_filter_bias() const
    {
        return static_cast<float>([cocoon::internal::ns<::CALayer>(this) minificationFilterBias]);
    }

    void CALayer::set_minification_filter_bias(float value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setMinificationFilterBias:static_cast<float>(value)];
    }

    std::string CALayer::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) name]);
    }

    void CALayer::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setName:cocoon::internal::to(value)];
    }

    bool CALayer::needs_display_on_bounds_change() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) needsDisplayOnBoundsChange]);
    }

    void CALayer::set_needs_display_on_bounds_change(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setNeedsDisplayOnBoundsChange:static_cast<::BOOL>(value)];
    }

    float CALayer::opacity() const
    {
        return static_cast<float>([cocoon::internal::ns<::CALayer>(this) opacity]);
    }

    void CALayer::set_opacity(float value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setOpacity:static_cast<float>(value)];
    }

    bool CALayer::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) isOpaque]);
    }

    void CALayer::set_opaque(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setOpaque:static_cast<::BOOL>(value)];
    }

    Point CALayer::position() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) position]);
    }

    void CALayer::set_position(const Point& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setPosition:cocoon::internal::to(value)];
    }

    std::string CALayer::preferred_dynamic_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) preferredDynamicRange]);
    }

    void CALayer::set_preferred_dynamic_range(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setPreferredDynamicRange:cocoon::internal::to(value)];
    }

    double CALayer::rasterization_scale() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) rasterizationScale]);
    }

    void CALayer::set_rasterization_scale(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setRasterizationScale:static_cast<::CGFloat>(value)];
    }

    CGColor CALayer::shadow_color() const
    {
        return cocoon::internal::wrap_cf<CGColor>((const void*)([cocoon::internal::ns<::CALayer>(this) shadowColor]));
    }

    void CALayer::set_shadow_color(const CGColor& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShadowColor:((::CGColorRef)(value).handle())];
    }

    Size CALayer::shadow_offset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) shadowOffset]);
    }

    void CALayer::set_shadow_offset(const Size& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShadowOffset:cocoon::internal::to(value)];
    }

    float CALayer::shadow_opacity() const
    {
        return static_cast<float>([cocoon::internal::ns<::CALayer>(this) shadowOpacity]);
    }

    void CALayer::set_shadow_opacity(float value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShadowOpacity:static_cast<float>(value)];
    }

    CGPath CALayer::shadow_path() const
    {
        return cocoon::internal::wrap_cf<CGPath>((const void*)([cocoon::internal::ns<::CALayer>(this) shadowPath]));
    }

    void CALayer::set_shadow_path(const CGPath& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShadowPath:((::CGPathRef)(value).handle())];
    }

    double CALayer::shadow_radius() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) shadowRadius]);
    }

    void CALayer::set_shadow_radius(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShadowRadius:static_cast<::CGFloat>(value)];
    }

    bool CALayer::should_rasterize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CALayer>(this) shouldRasterize]);
    }

    void CALayer::set_should_rasterize(bool value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setShouldRasterize:static_cast<::BOOL>(value)];
    }

    std::vector<std::pair<Object, Object>> CALayer::style() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::CALayer>(this) style], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    void CALayer::set_style(const std::vector<std::pair<Object, Object>>& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setStyle:cocoon::internal::to_dictionary(value, [](const Object& k) -> id
                                                                                        {
                                                                                            return cocoon::internal::native_id(k);
                                                                                        },
                                                                                        [](const Object& v) -> id
                                                                                        {
                                                                                            return cocoon::internal::native_id(v);
                                                                                        })];
    }

    CATransform3D CALayer::sublayer_transform() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) sublayerTransform]);
    }

    void CALayer::set_sublayer_transform(const CATransform3D& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setSublayerTransform:cocoon::internal::to(value)];
    }

    std::vector<CALayer> CALayer::sublayers() const
    {
        return cocoon::internal::from_array<CALayer>([cocoon::internal::ns<::CALayer>(this) sublayers], [](id e) -> CALayer
                                                     {
                                                         return cocoon::internal::wrap<CALayer>((::CALayer*)e);
                                                     });
    }

    void CALayer::set_sublayers(const std::vector<CALayer>& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setSublayers:cocoon::internal::to_array(value, [](const CALayer& e) -> id
                                                                                       {
                                                                                           return cocoon::internal::native<::CALayer>(e);
                                                                                       })];
    }

    CALayer CALayer::superlayer() const
    {
        return cocoon::internal::wrap<CALayer>([cocoon::internal::ns<::CALayer>(this) superlayer]);
    }

    std::string CALayer::tone_map_mode() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) toneMapMode]);
    }

    void CALayer::set_tone_map_mode(const std::string& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setToneMapMode:cocoon::internal::to(value)];
    }

    CATransform3D CALayer::transform() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CALayer>(this) transform]);
    }

    void CALayer::set_transform(const CATransform3D& value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setTransform:cocoon::internal::to(value)];
    }

    double CALayer::z_position() const
    {
        return static_cast<double>([cocoon::internal::ns<::CALayer>(this) zPosition]);
    }

    void CALayer::set_z_position(double value) const
    {
        [cocoon::internal::ns<::CALayer>(this) setZPosition:static_cast<::CGFloat>(value)];
    }

    void CALayer::install_delegate_delegate_(void* native)
    {
        ::CALayer* host = (__bridge ::CALayer*)native;
        AKCALayerDelegate* delegate = [[AKCALayerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::CALayer* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::CALayer* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
