#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGColor;
    class CGContext;
    class CGPath;

    /**
     * @brief C++ handle for the Objective-C class `CALayer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CALayer ca_layer;
     * ca_layer.display_layer().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CALayer ca_layer{};
     * ca_layer.set_allows_edge_antialiasing(true);
     * auto allows_edge_antialiasing = ca_layer.allows_edge_antialiasing();
     * ca_layer.set_allows_group_opacity(true);
     * auto allows_group_opacity = ca_layer.allows_group_opacity();
     * ca_layer.set_anchor_point({0, 0});
     * auto anchor_point = ca_layer.anchor_point();
     * auto made_0 = cocoon::CALayer::layer();
     * ca_layer.action_for_key("text");
     * ca_layer.add_sublayer(cocoon::CALayer());
     * ca_layer.affine_transform();
     * ca_layer.display_layer().connect([]() {});
     * ca_layer.draw_layer_in_context().connect([](cocoon::CGContext a0) {});
     * ca_layer.layer_will_draw().connect([]() {});
     * @endcode
     */
    class CALayer : public Object
    {
    public:
        /// @brief Creates a new `CALayer` instance and returns a handle to it.
        explicit CALayer(const Object& layer);
        /// @brief Creates a new `CALayer` instance and returns a handle to it.
        explicit CALayer();
        /// @brief Creates a null handle that refers to no native object.
        CALayer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CALayer(Adopt adopt);
        /**
     * @brief Calls `-[CALayer actionForKey:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object action_for_key(const std::string& event) const;
        /**
     * @brief Calls `-[CALayer addAnimation:forKey:]`.
     * @param anim Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void add_animation(const Object& anim, const std::string& key) const;
        /**
     * @brief Calls `-[CALayer addSublayer:]`.
     * @param layer Argument converted to the Objective-C parameter of the same role.
     */
        void add_sublayer(const CALayer& layer) const;
        /**
     * @brief Calls `-[CALayer affineTransform]`.
     * @return The converted Objective-C result.
     */
        AffineTransform3 affine_transform() const;
        /**
     * @brief Calls `-[CALayer animationForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object animation_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[CALayer animationKeys]`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> animation_keys() const;
        /**
     * @brief Calls `-[CALayer containsPoint:]`.
     * @param p Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_point(const Point& p) const;
        /**
     * @brief Calls `-[CALayer contentsAreFlipped]`.
     * @return The converted Objective-C result.
     */
        bool contents_are_flipped() const;
        /**
     * @brief Calls `-[CALayer convertPoint:fromLayer:]`.
     * @param p Argument converted to the Objective-C parameter of the same role.
     * @param l Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point convert_point(const Point& p, const CALayer& l) const;
        /**
     * @brief Calls `-[CALayer convertRect:fromLayer:]`.
     * @param r Argument converted to the Objective-C parameter of the same role.
     * @param l Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect convert_rect(const Rect& r, const CALayer& l) const;
        /**
     * @brief Calls `-[CALayer convertTime:fromLayer:]`.
     * @param t Argument converted to the Objective-C parameter of the same role.
     * @param l Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double convert_time(double t, const CALayer& l) const;
        /**
     * @brief Calls `+[CALayer cornerCurveExpansionFactor:]`.
     * @param curve Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static double corner_curve_expansion_factor(const std::string& curve);
        /**
     * @brief Calls `+[CALayer defaultActionForKey:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object default_action_for_key(const std::string& event);
        /**
     * @brief Calls `+[CALayer defaultValueForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object default_value_for_key(const std::string& key);
        /**
     * @brief Calls `-[CALayer display]`.
     */
        void display() const;
        /**
     * @brief Calls `-[CALayer displayIfNeeded]`.
     */
        void display_if_needed() const;
        /**
     * @brief Calls `-[CALayer drawInContext:]`.
     * @param ctx Argument converted to the Objective-C parameter of the same role.
     */
        void draw_in_context(const CGContext& ctx) const;
        /**
     * @brief Calls `-[CALayer hitTest:]`.
     * @param p Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CALayer hit_test(const Point& p) const;
        /**
     * @brief Calls `-[CALayer insertSublayer:above:]`.
     * @param layer Argument converted to the Objective-C parameter of the same role.
     * @param sibling Argument converted to the Objective-C parameter of the same role.
     */
        void insert_sublayer(const CALayer& layer, const CALayer& sibling) const;
        /**
     * @brief Calls `-[CALayer insertSublayer:atIndex:]`.
     * @param layer Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     */
        void insert_sublayer(const CALayer& layer, unsigned int idx) const;
        /**
     * @brief Calls `+[CALayer layer]`.
     * @return The converted Objective-C result.
     */
        static CALayer layer();
        /**
     * @brief Calls `-[CALayer layoutIfNeeded]`.
     */
        void layout_if_needed() const;
        /**
     * @brief Calls `-[CALayer layoutSublayers]`.
     */
        void layout_sublayers() const;
        /**
     * @brief Calls `-[CALayer modelLayer]`.
     * @return The converted Objective-C result.
     */
        CALayer model_layer() const;
        /**
     * @brief Calls `-[CALayer needsDisplay]`.
     * @return The converted Objective-C result.
     */
        bool needs_display() const;
        /**
     * @brief Calls `+[CALayer needsDisplayForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool needs_display_for_key(const std::string& key);
        /**
     * @brief Calls `-[CALayer needsLayout]`.
     * @return The converted Objective-C result.
     */
        bool needs_layout() const;
        /**
     * @brief Calls `-[CALayer preferredFrameSize]`.
     * @return The converted Objective-C result.
     */
        Size preferred_frame_size() const;
        /**
     * @brief Calls `-[CALayer presentationLayer]`.
     * @return The converted Objective-C result.
     */
        CALayer presentation_layer() const;
        /**
     * @brief Calls `-[CALayer removeAllAnimations]`.
     */
        void remove_all_animations() const;
        /**
     * @brief Calls `-[CALayer removeAnimationForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void remove_animation_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[CALayer removeFromSuperlayer]`.
     */
        void remove_from_superlayer() const;
        /**
     * @brief Calls `-[CALayer renderInContext:]`.
     * @param ctx Argument converted to the Objective-C parameter of the same role.
     */
        void render_in_context(const CGContext& ctx) const;
        /**
     * @brief Calls `-[CALayer replaceSublayer:with:]`.
     * @param old_layer Argument converted to the Objective-C parameter of the same role.
     * @param new_layer Argument converted to the Objective-C parameter of the same role.
     */
        void replace_sublayer(const CALayer& old_layer, const CALayer& new_layer) const;
        /**
     * @brief Calls `-[CALayer resizeSublayersWithOldSize:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     */
        void resize_sublayers_with_old_size(const Size& size) const;
        /**
     * @brief Calls `-[CALayer resizeWithOldSuperlayerSize:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     */
        void resize_with_old_superlayer_size(const Size& size) const;
        /**
     * @brief Calls `-[CALayer setAffineTransform:]`.
     * @param m Argument converted to the Objective-C parameter of the same role.
     */
        void set_affine_transform(const AffineTransform3& m) const;
        /**
     * @brief Calls `-[CALayer setNeedsDisplay]`.
     */
        void set_needs_display() const;
        /**
     * @brief Calls `-[CALayer setNeedsDisplayInRect:]`.
     * @param r Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_display_in_rect(const Rect& r) const;
        /**
     * @brief Calls `-[CALayer setNeedsLayout]`.
     */
        void set_needs_layout() const;
        /**
     * @brief Calls `-[CALayer shouldArchiveValueForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_archive_value_for_key(const std::string& key) const;
        /**
     * @brief Returns the `actions` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> actions() const;
        /**
     * @brief Sets the `actions` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_actions(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `allowsEdgeAntialiasing` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool allows_edge_antialiasing() const;
        /**
     * @brief Sets the `allowsEdgeAntialiasing` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_edge_antialiasing(bool value) const;
        /**
     * @brief Returns the `allowsGroupOpacity` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool allows_group_opacity() const;
        /**
     * @brief Sets the `allowsGroupOpacity` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_group_opacity(bool value) const;
        /**
     * @brief Returns the `anchorPoint` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Point anchor_point() const;
        /**
     * @brief Sets the `anchorPoint` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_anchor_point(const Point& value) const;
        /**
     * @brief Returns the `anchorPointZ` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double anchor_point_z() const;
        /**
     * @brief Sets the `anchorPointZ` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_anchor_point_z(double value) const;
        /**
     * @brief Returns the `autoresizingMask` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CAAutoresizingMask autoresizing_mask() const;
        /**
     * @brief Sets the `autoresizingMask` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoresizing_mask(CAAutoresizingMask value) const;
        /**
     * @brief Returns the `backgroundColor` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CGColor background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const CGColor& value) const;
        /**
     * @brief Returns the `backgroundFilters` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> background_filters() const;
        /**
     * @brief Sets the `backgroundFilters` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_filters(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `borderColor` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CGColor border_color() const;
        /**
     * @brief Sets the `borderColor` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_border_color(const CGColor& value) const;
        /**
     * @brief Returns the `borderWidth` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double border_width() const;
        /**
     * @brief Sets the `borderWidth` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_border_width(double value) const;
        /**
     * @brief Returns the `bounds` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Rect bounds() const;
        /**
     * @brief Sets the `bounds` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds(const Rect& value) const;
        /**
     * @brief Returns the `compositingFilter` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Object compositing_filter() const;
        /**
     * @brief Sets the `compositingFilter` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_compositing_filter(const Object& value) const;
        /**
     * @brief Returns the `contents` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Object contents() const;
        /**
     * @brief Sets the `contents` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents(const Object& value) const;
        /**
     * @brief Returns the `contentsCenter` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Rect contents_center() const;
        /**
     * @brief Sets the `contentsCenter` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_center(const Rect& value) const;
        /**
     * @brief Returns the `contentsFormat` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string contents_format() const;
        /**
     * @brief Sets the `contentsFormat` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_format(const std::string& value) const;
        /**
     * @brief Returns the `contentsGravity` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string contents_gravity() const;
        /**
     * @brief Sets the `contentsGravity` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_gravity(const std::string& value) const;
        /**
     * @brief Returns the `contentsHeadroom` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double contents_headroom() const;
        /**
     * @brief Sets the `contentsHeadroom` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_headroom(double value) const;
        /**
     * @brief Returns the `contentsRect` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Rect contents_rect() const;
        /**
     * @brief Sets the `contentsRect` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_rect(const Rect& value) const;
        /**
     * @brief Returns the `contentsScale` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double contents_scale() const;
        /**
     * @brief Sets the `contentsScale` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents_scale(double value) const;
        /**
     * @brief Returns the `cornerCurve` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string corner_curve() const;
        /**
     * @brief Sets the `cornerCurve` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_corner_curve(const std::string& value) const;
        /**
     * @brief Returns the `cornerRadius` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double corner_radius() const;
        /**
     * @brief Sets the `cornerRadius` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_corner_radius(double value) const;
        /**
     * @brief Returns the `doubleSided` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool is_double_sided() const;
        /**
     * @brief Sets the `doubleSided` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_sided(bool value) const;
        /**
     * @brief Returns the `drawsAsynchronously` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool draws_asynchronously() const;
        /**
     * @brief Sets the `drawsAsynchronously` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_asynchronously(bool value) const;
        /**
     * @brief Returns the `edgeAntialiasingMask` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CAEdgeAntialiasingMask edge_antialiasing_mask() const;
        /**
     * @brief Sets the `edgeAntialiasingMask` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_edge_antialiasing_mask(CAEdgeAntialiasingMask value) const;
        /**
     * @brief Returns the `filters` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> filters() const;
        /**
     * @brief Sets the `filters` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_filters(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `frame` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Sets the `frame` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame(const Rect& value) const;
        /**
     * @brief Returns the `geometryFlipped` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool is_geometry_flipped() const;
        /**
     * @brief Sets the `geometryFlipped` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_geometry_flipped(bool value) const;
        /**
     * @brief Returns the `hidden` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `layoutManager` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Object layout_manager() const;
        /**
     * @brief Sets the `layoutManager` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_manager(const Object& value) const;
        /**
     * @brief Returns the `magnificationFilter` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string magnification_filter() const;
        /**
     * @brief Sets the `magnificationFilter` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_magnification_filter(const std::string& value) const;
        /**
     * @brief Returns the `mask` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CALayer mask() const;
        /**
     * @brief Sets the `mask` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_mask(const CALayer& value) const;
        /**
     * @brief Returns the `maskedCorners` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CACornerMask masked_corners() const;
        /**
     * @brief Sets the `maskedCorners` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_masked_corners(CACornerMask value) const;
        /**
     * @brief Returns the `masksToBounds` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool masks_to_bounds() const;
        /**
     * @brief Sets the `masksToBounds` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_masks_to_bounds(bool value) const;
        /**
     * @brief Returns the `minificationFilter` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string minification_filter() const;
        /**
     * @brief Sets the `minificationFilter` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minification_filter(const std::string& value) const;
        /**
     * @brief Returns the `minificationFilterBias` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        float minification_filter_bias() const;
        /**
     * @brief Sets the `minificationFilterBias` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minification_filter_bias(float value) const;
        /**
     * @brief Returns the `name` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `needsDisplayOnBoundsChange` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool needs_display_on_bounds_change() const;
        /**
     * @brief Sets the `needsDisplayOnBoundsChange` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_display_on_bounds_change(bool value) const;
        /**
     * @brief Returns the `opacity` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        float opacity() const;
        /**
     * @brief Sets the `opacity` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_opacity(float value) const;
        /**
     * @brief Returns the `opaque` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Sets the `opaque` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_opaque(bool value) const;
        /**
     * @brief Returns the `position` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Point position() const;
        /**
     * @brief Sets the `position` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_position(const Point& value) const;
        /**
     * @brief Returns the `preferredDynamicRange` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string preferred_dynamic_range() const;
        /**
     * @brief Sets the `preferredDynamicRange` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_dynamic_range(const std::string& value) const;
        /**
     * @brief Returns the `rasterizationScale` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double rasterization_scale() const;
        /**
     * @brief Sets the `rasterizationScale` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rasterization_scale(double value) const;
        /**
     * @brief Returns the `shadowColor` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CGColor shadow_color() const;
        /**
     * @brief Sets the `shadowColor` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow_color(const CGColor& value) const;
        /**
     * @brief Returns the `shadowOffset` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        Size shadow_offset() const;
        /**
     * @brief Sets the `shadowOffset` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow_offset(const Size& value) const;
        /**
     * @brief Returns the `shadowOpacity` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        float shadow_opacity() const;
        /**
     * @brief Sets the `shadowOpacity` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow_opacity(float value) const;
        /**
     * @brief Returns the `shadowPath` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CGPath shadow_path() const;
        /**
     * @brief Sets the `shadowPath` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow_path(const CGPath& value) const;
        /**
     * @brief Returns the `shadowRadius` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double shadow_radius() const;
        /**
     * @brief Sets the `shadowRadius` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shadow_radius(double value) const;
        /**
     * @brief Returns the `shouldRasterize` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        bool should_rasterize() const;
        /**
     * @brief Sets the `shouldRasterize` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_rasterize(bool value) const;
        /**
     * @brief Returns the `style` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> style() const;
        /**
     * @brief Sets the `style` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_style(const std::vector<std::pair<Object, Object>>& value) const;
        /**
     * @brief Returns the `sublayerTransform` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CATransform3D sublayer_transform() const;
        /**
     * @brief Sets the `sublayerTransform` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sublayer_transform(const CATransform3D& value) const;
        /**
     * @brief Returns the `sublayers` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::vector<CALayer> sublayers() const;
        /**
     * @brief Sets the `sublayers` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sublayers(const std::vector<CALayer>& value) const;
        /**
     * @brief Returns the `superlayer` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CALayer superlayer() const;
        /**
     * @brief Returns the `toneMapMode` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        std::string tone_map_mode() const;
        /**
     * @brief Sets the `toneMapMode` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tone_map_mode(const std::string& value) const;
        /**
     * @brief Returns the `transform` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        CATransform3D transform() const;
        /**
     * @brief Sets the `transform` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transform(const CATransform3D& value) const;
        /**
     * @brief Returns the `zPosition` property of `CALayer`.
     * @return The converted Objective-C result.
     */
        double z_position() const;
        /**
     * @brief Sets the `zPosition` property of `CALayer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_z_position(double value) const;
        /// @brief Signal for the delegate/data-source method behind `display_layer`; connect a callback with `display_layer().connect(...)`.
        Signal<CALayer, void()> display_layer() const
        {
            return Signal<CALayer, void()>(handle(), "display_layer");
        }
        /// @brief Signal for the delegate/data-source method behind `draw_layer_in_context`; connect a callback with `draw_layer_in_context().connect(...)`.
        Signal<CALayer, void(CGContext)> draw_layer_in_context() const
        {
            return Signal<CALayer, void(CGContext)>(handle(), "draw_layer_in_context");
        }
        /// @brief Signal for the delegate/data-source method behind `layer_will_draw`; connect a callback with `layer_will_draw().connect(...)`.
        Signal<CALayer, void()> layer_will_draw() const
        {
            return Signal<CALayer, void()>(handle(), "layer_will_draw");
        }
        /// @brief Signal for the delegate/data-source method behind `layout_sublayers_of_layer`; connect a callback with `layout_sublayers_of_layer().connect(...)`.
        Signal<CALayer, void()> layout_sublayers_of_layer() const
        {
            return Signal<CALayer, void()>(handle(), "layout_sublayers_of_layer");
        }
        /// @brief Signal for the delegate/data-source method behind `action_for_layer_for_key`; connect a callback with `action_for_layer_for_key().connect(...)`.
        Signal<CALayer, Object(std::string)> action_for_layer_for_key() const
        {
            return Signal<CALayer, Object(std::string)>(handle(), "action_for_layer_for_key");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
